#include <stdint.h>

volatile uint8_t *uart = (uin8t *) 0x9000000;

void putchar(char c) {
	*uart = c;
}

void print(const char *s) {
	while(*s != '\0') {
		putchar(*s);
		s++;
	}
}

void kmain(void) {
	print("Hello World!\n");
}
