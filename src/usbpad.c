#include "globals.h"
#include "usbdrv.h"
#include "psx.h"
#include "spi.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define REPORT_TYPE_INPUT 1
#define REPORT_TYPE_OUTPUT 2
#define REPORT_TYPE_FEATURE 3
#define FEATURE_BLOCK_LOAD_STATUS 2
#define FEATURE_ROM_POOL_SIZE 3

#define START_TIMER1 SET_BITS(TCCR1B,CS12,CS10)
#define STOP_TIMER1  TCCR1B &= 0B11111000
#define CLEAR_TIMER1 TCNT1 = 0

typedef struct {
	bool f0:1;
	bool f1:1;
	bool f2:1;
	bool f3:1;
	bool f4:1;
	bool f5:1;
	bool f6:1;
	bool f7:1;
} PackedBool;
#define effects		( (volatile PackedBool*)(&GPIOR0) )->f2 //deben reproducirse los efectos?
#define changed     ( (volatile PackedBool*)(&GPIOR0) )->f3 //ha cambiado el report?
#define sMotor_en	( (volatile PackedBool*)(&GPIOR0) )->f0 //debe activarse el motor pequeño? constant
#define bMotor_en	( (volatile PackedBool*)(&GPIOR0) )->f1 //debe activarse el motor grande? ramp
uint16_t sdur = 1; //duracion del efecto en segundos
uint16_t bdur = 1;
static unsigned char bMotor_str = 0xFF; //magnitud del motor grande
volatile unsigned char bMotor, sMotor;
unsigned char report[8];
unsigned char efreport2[5] = { 2, 1, 1, 255, 255 };
unsigned char efreport3[5] = { 3, 255, 255, 2, 255 };
/* ----------------------- hardware I/O abstraction ------------------------ */

static void hardwareInit(void) {
	uchar i, j;
	DDRB = 0x2F; // 00101111 PORTB; everythin output, except MISO
	PORTB = 0x04; // 0000100 ATT lines, uses CS and another pin
	PORTC = 0; // Don't need these atm.
	DDRC = 0; // Don't need these atm.
	PORTD = 0xEB; /* 1111 0011 bin: activate pull-ups except on USB lines */
	DDRD = 0x14; /* 0000 1100 bin: all pins input except USB (-> USB reset) */
	j = 0;
	while (--j) { /* USB Reset by device only required on Watchdog Reset */
		i = 0;
		while (--i)
			; /* delay >10ms for USB reset */
	}
	DDRD = 0x10; /* 0000 1000 bin: remove USB reset condition */
}

/* ------------------------------------------------------------------------- */

usbMsgLen_t usbFunctionSetup(uchar data[8]) {
	usbRequest_t *rq = (void *) data;

	if ((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS) { /* class request type */
		if (rq->bRequest == USBRQ_HID_GET_REPORT) {
			if (rq->wValue.bytes[1] == REPORT_TYPE_INPUT) {
				usbMsgPtr = report;
				return 8;
			} else if (rq->wValue.bytes[1] == REPORT_TYPE_FEATURE) {
				if (rq->wValue.bytes[0] == FEATURE_BLOCK_LOAD_STATUS) {
					usbMsgPtr = efreport2;
					return 5;
				} else if (rq->wValue.bytes[0] == FEATURE_ROM_POOL_SIZE) {
					usbMsgPtr = efreport3;
					return 5;
				}//pool
			}//feature
		} else if (rq->bRequest == USBRQ_HID_SET_REPORT) {
			return USB_NO_MSG;
		}//set
	}//class
	return 0;
}
uchar usbFunctionWrite(uchar *data, uchar len) {
	/* el report 1 manda el efecto y la duración
	 * el report 5 manda la velocidad de giro
	 * el report 6 manda inicio y fin de la rampa (que no usamos)
	 * el report 10 manda si ejecutar o parar los efectos
	 * el report 12 para los efectos
	 * NOTA: Mientras no haya un reset(12) los efectos pueden reutilizarse lanzando un 10-1
	 */
	if (data[0] == 5) { //fuerza cte seleccionado
		if (data[2]) {
			bMotor_str = data[2];//fuerza
		} else {
			bMotor_str = 0xFF;
		}
	} else if (data[0] == 6) { //ramp
		sMotor_en = 1;
	} else if (data[0] == 10) {//operation
		if (data[1] == 1) { //cte
			if (data[2] == 1) { //start
				bMotor_en = 1;
			} else if (data[2] == 3) {//stop
				bMotor_en = 0;
			}
		} else if (data[1] == 2) {//ramp
			if (data[2] == 1) { //start
				sMotor_en = 1;
			} else if (data[2] == 3) {//stop
				sMotor_en = 0;
			}
		}
	} else if (data[0] == 12) { //reset device
		effects = 0;
		sMotor_en = 0;
		bMotor_en = 0;
		sMotor = 0;
		bMotor = 0;
		sdur = 2;
		bdur = 2;
	} else if (data[0] == 1) {
		if (len == 4) { //es un feature
			efreport2[1] = data[1];
		} else if (data[2] == 1) {//cte
			bdur = (data[3] + (data[4] << 8));
		} else if (data[2] == 2) {//ramp
			sdur = (data[3] + (data[4] << 8));
		}
	}
	return 1;
}

/* ------------------------------------------------------------------------- */
//cuando salta la int, apaga el efecto
ISR(TIMER1_COMPA_vect)
{ //small motor
	sMotor = 0x00;
	CLEAR_BITS(TIMSK1, OCIE1A);//desactivar las interrupciones
}
ISR(TIMER1_COMPB_vect)
{ //big motor
	bMotor = 0x00;
	CLEAR_BITS(TIMSK1, OCIE1B);//desactivar las interrupciones
}
/* ------------------------------------------------------------------------- */

int main(void) {
	hardwareInit();
	usbDeviceDisconnect();
	_delay_ms(300UL);
	usbDeviceConnect();
	usbInit();
	START_TIMER1; // arrancar el timer a Fcpu/1024
	spi_mInit(); // SPI
	psxInit();

	unsigned char x = 0;
	static uchar outBuffer[8];

	// Main loop
	// This loop checks one gamepad, if the state of buttons changed, it waits untill it can send the data and then send it,
	sei();
	for (;;) {
			//procesa efectos
			if (sMotor_en) {
				//activar el motor pequeño
				SET_BITS(TIMSK1, OCIE1A); //activar interrupcion a
				OCR1A = TCNT1 + (sdur * 11); // cargar registro a
				sMotor = 0xFF; //activar el motor
				sMotor_en = 0;
			}
			if (bMotor_en) {
				SET_BITS(TIMSK1, OCIE1B); //activar interrupcion b
				OCR1B = TCNT1 + (bdur * 11); // cargar registro b
				bMotor = bMotor_str;
				bMotor_en = 0;
			}
		usbPoll();
		psxtalk(report, sMotor, bMotor);
		for (x = 0; x < 8; x++) {
			if (outBuffer[x] != report[x]) {
				changed = 1;
			}
		}
		if (changed == 1) {
			while (!usbInterruptIsReady()) {
				usbPoll();
			}
			usbSetInterrupt(report, 8);
			for (x = 0; x < 8; x++) {
				outBuffer[x] = report[x];
			}
			changed = 0;
		}
	}
}