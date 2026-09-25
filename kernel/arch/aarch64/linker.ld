ENTRY(_start)
SECTIONS {
	/* RAM starts at 0x4000_0000 */
	. = 0x40000000;

	.text : { 
		*.(.text.boot)
		*.(.text)
	}

	.data : { *(.data) }

	.bss : {
		__bss_start = .;
		*(.bss)
		__bss_end = .;
	}

	/* Align the stack, 4KB alignment */
	. = ALIGN(16);
	. += 4096;
	_stack_top = .;	
}
