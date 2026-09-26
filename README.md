# protos

I'm going to be creating an OS, just to expand my own knowledge and understanding. Also maybe try 
and figure out why OS Engineers are swearing at their computer all the time.

The OS is designed on aarch64, for now, no particular reason other then I want to learn that specific architecture.

The board that is supported is the QEMU virt board, so no physical hardware all virtualized, perhaps one day RPI? TBD.

Okay so we currently have a .bss section, we still need a .rodata section

Here is the current symbol table:
```
~/Projects/alpha/kernel nsabharwal-init* ❯ ~/opt/cross/bin/aarch64-none-elf-readelf -s protos.elf                                                                                                            10:16:51

Symbol table '.symtab' contains 27 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000040000180     0 SECTION LOCAL  DEFAULT    1 .bss
     2: 0000000000000000     0 SECTION LOCAL  DEFAULT    2 .comment
     3: 0000000040000000     0 SECTION LOCAL  DEFAULT    3 .text
     4: 0000000040000118     0 SECTION LOCAL  DEFAULT    4 .text.boot
     5: 0000000040000170     0 SECTION LOCAL  DEFAULT    5 .rodata
     6: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS uart.c
     7: 0000000040000000     0 NOTYPE  LOCAL  DEFAULT    3 $x
     8: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS boot.o
     9: 0000000040000118     0 NOTYPE  LOCAL  DEFAULT    4 $x
    10: 0000000040000128     0 NOTYPE  LOCAL  DEFAULT    4 .EL1_INITIALIZE
    11: 000000004000013c     0 NOTYPE  LOCAL  DEFAULT    4 .bss_clear
    12: 000000004000014c     0 NOTYPE  LOCAL  DEFAULT    4 .CALL_KMAIN
    13: 0000000040000158     0 NOTYPE  LOCAL  DEFAULT    4 $d
    14: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS protos.c
    15: 0000000040000170     0 NOTYPE  LOCAL  DEFAULT    5 $d
    16: 00000000400000f0     0 NOTYPE  LOCAL  DEFAULT    3 $x
    17: 0000000040000180     0 NOTYPE  GLOBAL DEFAULT    1 __bss_end
    18: 000000004000008c    68 FUNC    GLOBAL DEFAULT    3 uart_puts
    19: 0000000040004180     0 NOTYPE  GLOBAL DEFAULT    1 _stack_top
    20: 0000000040000000    80 FUNC    GLOBAL DEFAULT    3 uart_init
    21: 0000000040000118     0 NOTYPE  GLOBAL DEFAULT    4 _start
    22: 0000000040000180     0 NOTYPE  GLOBAL DEFAULT    1 __bss_start
    23: 0000000040000050    60 FUNC    GLOBAL DEFAULT    3 uart_putc
    24: 0000000040000180     0 NOTYPE  GLOBAL DEFAULT    1 _stack_end
    25: 00000000400000d0    32 FUNC    GLOBAL DEFAULT    3 kprintf
    26: 00000000400000f0    36 FUNC    GLOBAL DEFAULT    3 kmain
```
