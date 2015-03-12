#include "spi.h"
#include <avr/io.h>
/* ----------------------Atmega8 SPI, master, 93.75khz---------------------- */

void spi_mInit()
{
	// SPI, master, clock/128 = 93.75khz (187.5 didn't work...)
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0)|(1<<DORD)|(1<<CPHA)|(1<<CPOL);
}

unsigned char spi_mSend(unsigned char podatek)	//straight from documentation
{
	// Gets information, sends it, waits untill it's sent, then reads the same register (used for both Input and Output) and returns it
	/* Start transmission */
	SPDR = podatek;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
