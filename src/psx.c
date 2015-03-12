#include "globals.h"
#include "psx.h"
#include "spi.h"
#include <avr/io.h>
#include <util/delay.h>

#define ATT 2
#define DZL 10
#define DZH 10

void psxInit(void) {
	//entrar modo config
	CLEAR_BITS(PORTB,ATT);
	_delay_ms(1);
	spi_mSend(0x01);
	_delay_us(100);
	spi_mSend(0x43);//config mode
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	spi_mSend(0x01);//entrar modo config
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	SET_BITS(PORTB,ATT);
	_delay_ms(8);
	//entrar modo analog
	CLEAR_BITS(PORTB,ATT);
	_delay_ms(1);
	spi_mSend(0x01);
	_delay_us(100);
	spi_mSend(0x44);
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	spi_mSend(0x01);
	_delay_us(100);
	spi_mSend(0x03);
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	SET_BITS(PORTB,ATT);
	_delay_ms(8);
	//activar motor control
	CLEAR_BITS(PORTB,ATT);
	_delay_ms(1);
	spi_mSend(0x01);
	_delay_us(100);
	spi_mSend(0x4D);//modo motor
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	spi_mSend(0x00);//motor pequeño?
	_delay_us(100);
	spi_mSend(0x01);//motor grande?
	_delay_us(100);
	spi_mSend(0xFF);
	_delay_us(100);
	spi_mSend(0xFF);
	_delay_us(100);
	spi_mSend(0xFF);
	_delay_us(100);
	spi_mSend(0xFF);
	_delay_us(100);
	SET_BITS(PORTB,ATT);
	_delay_ms(8);
	//salir modo config
	CLEAR_BITS(PORTB,ATT);
	_delay_ms(1);
	spi_mSend(0x01);
	_delay_us(100);
	spi_mSend(0x43);
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	spi_mSend(0x00);
	_delay_us(100);
	spi_mSend(0x5A);
	_delay_us(100);
	spi_mSend(0x5A);
	_delay_us(100);
	spi_mSend(0x5A);
	_delay_us(100);
	spi_mSend(0x5A);
	_delay_us(100);
	spi_mSend(0x5A);
	_delay_us(100);
	SET_BITS(PORTB,ATT);
	_delay_ms(8);
}

void psxtalk(unsigned char* report, _Bool sMotor, unsigned char bMotor) {
	static unsigned char psxbuffer[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	static unsigned char type = 0;
	//lee datos
	CLEAR_BITS(PORTB,ATT);
	_delay_ms(1);
	psxbuffer[0] = spi_mSend(0x01); // We want data!
	_delay_us(100);
	psxbuffer[1] = spi_mSend(0x42); // What's your model? (use later)
	_delay_us(100);
	if (psxbuffer[1] == 0x41) { // Digital pad, possibly DDR Pad
		psxbuffer[2] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[3] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[4] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[5] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[6] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[7] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[8] = spi_mSend(0x00);
	}
	if (psxbuffer[1] == 0x73) {// Standard Analog pad in RED mode
		psxbuffer[2] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[3] = spi_mSend(sMotor); //small motor
		_delay_us(100);
		psxbuffer[4] = spi_mSend(bMotor); //big motor
		_delay_us(100);
		psxbuffer[5] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[6] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[7] = spi_mSend(0x00);
		_delay_us(100);
		psxbuffer[8] = spi_mSend(0x00);
	} else {
		psxbuffer[2] = 0;
		psxbuffer[3] = 0;
		psxbuffer[4] = 0;
		psxbuffer[5] = 0;
		psxbuffer[6] = 0;
		psxbuffer[7] = 0;
		psxbuffer[8] = 0;
	}
	SET_BITS(PORTB,ATT);
	_delay_ms(1);

	//interpreta datos
	int temp1 = 255 - psxbuffer[3];
	int temp2 = 255 - psxbuffer[4];

	report[0] = 0x01;

	if (psxbuffer[1] == 0x41) { // Digital pad

		// Zero the unused axes
		report[2] = 0x80;
		report[3] = 0x80;
		report[4] = 0x80;
		report[5] = 0x80;

		// Buttons!
		report[6] = ((temp1 & 0x01) << 0) | ((temp1 & 0x08) >> 2) | ((temp2
				& 0x01) << 2) | ((temp2 & 0x02) << 2) | ((temp2 & 0x04) << 2)
				| ((temp2 & 0x08) << 2) | ((temp2 & 0x10) << 2) | ((temp2
				& 0x20) << 2);

		report[7] = ((temp2 & 0x40) >> 6) | ((temp2 & 0x80) >> 6) | ((temp1
				& 0x02) << 1) | ((temp1 & 0x04) << 1);

		if (type < 200) {
			// Up, Down - Y! Axis
			if (temp1 & 0x10) {
				report[1] = 0x00;
			} else if (temp1 & 0x40) {
				report[1] = 0xF0;
			} else {
				report[1] = 0x80;
			}

			// Right, Left - X! Axis
			if (temp1 & 0x20) {
				report[1] = report[1] + 0x0F;
			} else if (temp1 & 0x80) {
				report[1] = report[1] + 0x00;
			} else {
				report[1] = report[1] + 0x08;
			}
			report[7] &= ~0x10 | ~0x20 | ~0x40 | ~0x80;
		} else {

			report[7] = ((temp2 & 0x40) >> 6) | ((temp2 & 0x80) >> 6) | ((temp1
					& 0x02) << 1) | ((temp1 & 0x04) << 1) | (temp1 & 0x10)
					| (temp1 & 0x20) | (temp1 & 0x40) | (temp1 & 0x80);
			report[1] = 0x88;
			type = 222;
		}

		if ((temp1 & 0x01) && (temp1 & 0x08) && (temp1 & 0x10)) {
			type++;
		}

	}

	else if (psxbuffer[1] == 0x73) { // Decode analog pad

		//deadzone 22% de 128 = 12 = 0x1B
		// Right stick, X axis
		if ((psxbuffer[5] > DZL) && (psxbuffer[5] < DZH)) {
			report[2] = 0x7F;
		} else {
			report[2] = psxbuffer[5];
		}
		// Right stick, Y axis
		if ((psxbuffer[6] > DZL) && (psxbuffer[6] < DZH)) {
			report[3] = 0x7F;
		} else {
			report[3] = psxbuffer[6];
		}
		// Left stick,  X axis
		if ((psxbuffer[7] > DZL) && (psxbuffer[7] < DZH)) {
			report[4] = 0x7F;
		} else {
			report[4] = psxbuffer[7];
		}
		// Left stick,  Y axis
		if ((psxbuffer[8] > DZL) && (psxbuffer[8] < DZH)) {
			report[5] = 0x7F;
		} else {
			report[5] = psxbuffer[8];
		}

		//Buttons, buttons, so many buttons!

		// Up, Down - Y! Axis
		if (temp1 & 0x10) {
			report[1] = 0x00;
		} else if (temp1 & 0x40) {
			report[1] = 0xF0;
		} else {
			report[1] = 0x80;
		}

		// Right, Left - X! Axis

		if (temp1 & 0x20) {
			report[1] = report[1] + 0x0F;
		} else if (temp1 & 0x80) {
			report[1] = report[1] + 0x00;
		} else {
			report[1] = report[1] + 0x08;
		}

		report[6] = ((temp1 & 0x01) << 0) | ((temp1 & 0x08) >> 2) | ((temp2
				& 0x01) << 2) | ((temp2 & 0x02) << 2) | ((temp2 & 0x04) << 2)
				| ((temp2 & 0x08) << 2) | ((temp2 & 0x10) << 2) | ((temp2
				& 0x20) << 2);

		report[7] = ((temp2 & 0x40) >> 6) | ((temp2 & 0x80) >> 6) | ((temp1
				& 0x02) << 1) | ((temp1 & 0x04) << 1);

		report[7] &= ~0x10 | ~0x20 | ~0x40 | ~0x80;

	} else { // If there isn't a pad connected, or if it is an unsupported one, zero the axes and the buttons
		report[1] = 0x88;
		report[2] = 0x80;
		report[3] = 0x80;
		report[4] = 0x80;
		report[5] = 0x80;
		report[6] = 0;
		report[7] = 0;
	}
}
