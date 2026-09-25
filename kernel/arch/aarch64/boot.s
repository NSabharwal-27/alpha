.section .text.boot
.global _start
_start:

	/* Sort out the Exception Level first. */
	mrs	x0, CurrentEL
	lsr	x0, x0, #2
	cmp	x0, #1
	beq	.EL1_INITIALIZE


.EL1_INITIALIZE:
	/* Now, setup the stack. */
	ldr	x9, =_stack_top
	mov	sp, x9

	/* Now that's done, go to kernel */
	bl	kmain
	b	.
