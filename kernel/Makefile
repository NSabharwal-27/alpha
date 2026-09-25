# Custom cross compilers that we built using the cross-compiler script
# The location of these is setup in that script so adjust as necessary.

CROSS		?= aarch64-none-elf
CROSS_SRC	?= ~/opt/cross/bin

CC = $(CROSS_SRC)/$(CROSS)-gcc
AS = $(CROSS_SRC)/$(CROSS)-as
LD = $(CROSS_SRC)/$(CROSS)-ld

ARCHDIR ?= ./arch/aarch64

# TODO:
# Seperate each of the commands for seperate rules too, maybe?
# This needs to be cleaner, need to figure out how.
all: kernel.c
	$(AS) $(ARCHDIR)/boot.s -o boot.o
	$(CC) -ffreestanding -c kernel.c -o kernel.o
	$(CC) -ffreestanding -c ./uart/uart.c -o uart.o
	$(LD) -nostdlib -T$(ARCHDIR)/linker.ld boot.o uart.o kernel.o -o kernel.elf

clean:
	rm *.o *.elf

run:
	qemu-system-aarch64 \
	-machine virt \
	-cpu cortex-a57 \
	-nographic \
	-kernel kernel.elf

.PHONY: all clean run
