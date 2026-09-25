# Custom cross compilers that we built using the cross-compiler script
# The location of these is setup in that script so adjust as necessary.

aarch: CC = ~/opt/cross/bin/aarch64-none-elf-gcc
aarch: AS = ~/opt/cross/bin/aarch64-none-elf-as
aarch: LD = ~/opt/cross/bin/aarch64-none-elf-ld

# TODO: remove ./arch/aarch64/ and replace with $(ARCHDIR)
# Seperate each of the commands for seperate rules too, maybe?
# This needs to be cleaner, need to figure out how.
aarch: kernel.c
	$(AS) ./arch/aarch64/boot.s -o boot.o 
	$(CC) -ffreestanding -c kernel.c -o kernel.o
	$(LD) -nostdlib -T./arch/aarch64/linker.ld boot.o kernel.o -o kernel.elf

clean:
	rm *.o *.elf
