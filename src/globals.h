#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <stdbool.h>
#ifndef F_CPU
#define F_CPU 20000000UL
#endif
#define USART_BAUDRATE 9600

#define BITS8(arg, ...) ((arg!=-1)?0<<-1:0)
#define BITS7(arg, bits...) ((arg>=0)? (1 <<(arg)):0) | BITS8(bits)
#define BITS6(arg, bits...) ((arg>=0)? (1 << (arg)):0) | BITS7(bits, -1)
#define BITS5(arg, bits...) ((arg>=0)? (1 << (arg)):0) | BITS6(bits, -1)
#define BITS4(arg, bits...) ((arg>=0)? (1 << (arg)):0) | BITS5(bits, -1)
#define BITS3(arg, bits...) ((arg>=0)? (1 << (arg)):0) | BITS4(bits, -1)
#define BITS2(arg, bits...) ((arg>=0)? (1 << (arg)):0) | BITS3(bits, -1)
#define BITS1(arg, bits...) ((arg>=0)? (1 << (arg)):0) | BITS2(bits, -1)
#define BITS0(arg, bits...) ((arg>=0)? (1 << (arg)):0) | BITS1(bits, -1)

#define SET_BITS(var, bits...)   var |=   BITS0(bits, -1)
#define CLEAR_BITS(var, bits...) var &= ~(BITS0(bits, -1))
#define LOAD_BITS(var, bits...)  var =    BITS0(bits, -1)

#endif /* INCFILE1_H_ */