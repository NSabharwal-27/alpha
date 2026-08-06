.global _start
_start:
	ldr x9, =stack_top
	mov sp, x9
	bl kmain
	b .
