aarch: CC = ~/opt/cross/bin/aarch64-none-elf-gcc
aarch: AS = ~/opt/cross/bin/aarch64-none-elf-as
aarch: LD = ~/opt/cross/bin/aarch64-none-elf-ld

aarch: kernel.c
	$(AS) ./arch/aarch64/boot.s -o boot.o 
	$(CC) -ffreestanding -c kernel.c -o kernel.o
	$(LD) -nostdlib -T./arch/aarch64/linker.ld boot.o kernel.o -o kernel.elf
	
kernel: kernel.c
	$(CC) -ffreestanding -c kernel.c -o kernel

clean:
	rm *.o *.elf
