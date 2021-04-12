#define 	inp(port)   (port)
#define 	outp(val, port)   (port) = (val)
#define 	inb(port)   (port)
#define 	outb(port, val)   (port) = (val)

#ifndef	sbi
#	define 	sbi(port, bit)   ((port) |= (1 << (bit)))
#endif

#ifndef	cbi
#	define 	cbi(port, bit)   ((port) &= ~(1 << (bit)))
#endif

#define 	inbit(port, bit)   ((port)&(1 << (bit)))

#ifndef	wdr
#	define 	wdr()   asm("wdr")
#endif

#ifndef	nop
#	define 	nop()   asm("nop")
#endif

#ifndef	wdr
#	define 	sei()   asm("sei")
#endif

#ifndef	nop
#	define 	cli()   asm("cli")
#endif


#define u8		uint8_t
#define u16		uint16_t
#define i8		int8_t
#define i16		int16_t

#define On 1
#define Off 0
#define on 1
#define off 0
#define ON 1
#define OFF 0

#define _b0 0x01
#define _b1 0x02
#define _b2 0x04
#define _b3 0x08
#define _b4 0x10
#define _b5 0x20
#define _b6 0x40
#define _b7 0x80

#define _ib0 255-0x01
#define _ib1 255-0x02
#define _ib2 255-0x04
#define _ib3 255-0x08
#define _ib4 255-0x10
#define _ib5 255-0x20
#define _ib6 255-0x40
#define _ib7 255-0x80



