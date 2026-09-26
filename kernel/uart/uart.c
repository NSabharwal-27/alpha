#include "uart.h"

/*
 * Initialize the hardware for PL011 registers
 */
void uart_init(void){
	/* Disable the MMIO first. */
	UART_ACCESS_REG(UARTCR) = UARTCR_DA;

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

	/*
	 * Okay so the next thing we have to do is setup the line
	 * I think we want 8 bits since in C, each char is 1 byte.
	 * Also, enable FIFO.
	 */
	UART_ACCESS_REG(UARTLCR_H) = UARTLCR_H_FEN | UARTLCR_H_WLEN;

	UART_ACCESS_REG(UARTCR) = UARTCR_EN | UARTCR_TXE | UARTCR_RXE;
}


void uart_putc(const char c){
	while(UART_ACCESS_REG(UARTFR) & UARTFR_TXFF)
		;
	UART_ACCESS_REG(UARTDR) = (uint32_t) c;
}


void uart_puts(const char *str){
	while(*str){
		uart_putc(*str++);
	}
}
