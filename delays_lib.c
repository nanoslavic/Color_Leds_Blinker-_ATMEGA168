/*
Delays with "wdr"
*/


#include <inttypes.h>

#if !defined(__DOXYGEN__)
static inline void delay_loop_1(uint8_t __count) __attribute__((always_inline));
static inline void delay_loop_2(uint16_t __count) __attribute__((always_inline));
static inline void delay_us(double __us) __attribute__((always_inline));
static inline void delay_ms(double __ms) __attribute__((always_inline));
#endif

#ifndef F_CPU
/* prevent compiler error by supplying a default */
# warning "F_CPU not defined for <util/delay.h>"
# define F_CPU 1000000UL
#endif

#ifndef __OPTIMIZE__
# warning "Compiler optimizations disabled; functions from <util/delay.h> won't work as designed"
#endif


/** \ingroup util_delay_basic

    Delay loop using an 8-bit counter \c __count, so up to 256
    iterations are possible.  (The value 256 would have to be passed
    as 0.)  The loop executes three CPU cycles per iteration, not
    including the overhead the compiler needs to setup the counter
    register.

    Thus, at a CPU speed of 1 MHz, delays of up to 768 microseconds
    can be achieved.
*/

void
delay_loop_1(uint8_t __count)
{
	__asm__ volatile (
		"1: dec %0" "\n\t"
		"wdr" "\n\t"
		"brne 1b"
		: "=r" (__count)
		: "0" (__count)
	);
}

/** \ingroup util_delay_basic

    Delay loop using a 16-bit counter \c __count, so up to 65536
    iterations are possible.  (The value 65536 would have to be
    passed as 0.)  The loop executes four CPU cycles per iteration,
    not including the overhead the compiler requires to setup the
    counter register pair.

    Thus, at a CPU speed of 1 MHz, delays of up to about 262.1
    milliseconds can be achieved.
 */
void
delay_loop_2(uint16_t __count)
{
	__asm__ volatile (
		"1: sbiw %0,1" "\n\t"
		"wdr" "\n\t"
		"brne 1b"
		: "=w" (__count)
		: "0" (__count)
	);
}

/**
   \ingroup util_delay

   Perform a delay of \c __ms milliseconds, using _delay_loop_2().

   The macro F_CPU is supposed to be defined to a
   constant defining the CPU clock frequency (in Hertz).

   The maximal possible delay is 262.14 ms / F_CPU in MHz.

   When the user request delay which exceed the maximum possible one,
   _delay_ms() provides a decreased resolution functionality. In this
   mode _delay_ms() will work with a resolution of 1/10 ms, providing
   delays up to 6.5535 seconds (independent from CPU frequency).  The
   user will not be informed about decreased resolution.
 */
void
delay_ms(double __ms)
{
	uint16_t __ticks;
	double __tmp = ((F_CPU) / 5e3) * __ms;
	if (__tmp < 1.0)
		__ticks = 1;
	else if (__tmp > 65535)
	{
		//	__ticks = requested delay in 1/10 ms
		__ticks = (uint16_t) (__ms * 10.0);
		while(__ticks)
		{
			// wait 1/10 ms
			delay_loop_2(((F_CPU) / 5e3) / 10);
			__ticks --;
		}
		return;
	}
	else
		__ticks = (uint16_t)__tmp;
	delay_loop_2(__ticks);
}


/**
   \ingroup util_delay

   Perform a delay of \c __us microseconds, using _delay_loop_1().

   The macro F_CPU is supposed to be defined to a
   constant defining the CPU clock frequency (in Hertz).

   The maximal possible delay is 768 us / F_CPU in MHz.

   If the user requests a delay greater than the maximal possible one,
   _delay_us() will automatically call _delay_ms() instead.  The user
   will not be informed about this case.
 */
void
delay_us(double __us)
{
	uint8_t __ticks;
	double __tmp = ((F_CPU) / 4e6) * __us;
	if (__tmp < 1.0)
		__ticks = 1;
	else if (__tmp > 255)
	{
		delay_ms(__us / 1000.0);
		return;
	}
	else
		__ticks = (uint8_t)__tmp;
	delay_loop_1(__ticks);
}

