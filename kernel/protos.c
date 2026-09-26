#include <stdint.h>
#include "uart/uart.h"

void kmain(void) {
	uart_init();
	uart_puts("Hello World!\n");
}
