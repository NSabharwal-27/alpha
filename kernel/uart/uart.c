#include "uart.h"

/*
 * Initialize the hardware for PL011 registers
 */
void uart_init(void){
	/* Disable the MMIO first. */
	UART_ACCESS_REG(UARTCR) = 0;

	/*
	 * QEMU virt defines the baud rate for the serial console to be
	 * 115200 and 24MHz clock, typical oversampling rates is 16.
	 * doing the math for the divisors
	 * Divisor = f_clock / baud * oversampling rate
	 *         = 24MHz / 115200 * 16
	 *         = 13.0208
	 */
	UART_ACCESS_REG(UARTIBRD) = 13;
	UART_ACCESS_REG(UARTFBRD) = 0;
}
