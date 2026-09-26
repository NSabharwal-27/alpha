ENTRY(_start)
SECTIONS {
	/* RAM starts at 0x4000_0000 */
	. = 0x40000000;

	.text : { 
		*.(.text.boot)
		*.(.text)
	}

	.data : { *(.data) }

	/* 
	 * We can do 16-byte or 8-byte alignment,
	 * it depends on the way that we clear the bss section
	 * in the assembly boot code. We will opt for 8.
	 */
	. = ALIGN(8);
	.bss : {
		__bss_start = .;
		*(.bss)
		. = ALIGN(8);
		__bss_end = .;
	}

	/* Align the stack, 16-byte alignment */
	. = ALIGN(16);
	_stack_end = .;
	/* 
	 * Reserve 16KB for the stack, we know
	 * it's already aligned.
	 */
	. += 0x4000;
	_stack_top = .;
}
