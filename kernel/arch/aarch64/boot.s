.global _start
_start:

	// Sort out the Exception Level first.
	mrs	x0, CurrentEL
	ubfx	x0, x1, #2, #2

	// Now, setup the stack.
	ldr	x9, =stack_top
	mov	sp, x9

	bl	kmain
	b	.
