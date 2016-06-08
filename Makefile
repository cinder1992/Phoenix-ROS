CROSS_TARGET = i686-elf
OPTIMISE=2
INCLUDE=./src/inc
ASMINCLUDE=$(INCLUDE)/x86

VPATH=src:src/x86

CC=$(CROSS_TARGET)-gcc
LD=$(CROSS_TARGET)-gcc
ASM=$(CROSS_TARGET)-as

LD_FILE=./src/linker.ld

OBJS=kstring.o vga.o kernel.o regdump.s.o _start.s.o

CC_FLAGS= -I$(INCLUDE) -c -O$(OPTIMISE) -Wall -Wextra -ffreestanding -std=gnu99
LD_FLAGS= -ffreestanding -nostdlib -O$(OPTIMISE)

.PHONY: all clean run-qemu

all: kernel.elf phoenix.iso

clean:
	rm -fv $(OBJS)
	rm -fv $(OBJS_x86)
	rm -fv kernel.elf
	rm -fvr isodir
	rm -fv phoenix.iso

kernel.elf: $(OBJS) $(OBJS_x86)
	$(LD) -T $(LD_FILE) -o kernel.elf $(LD_FLAGS) $^ -lgcc

phoenix.iso: 
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub
	cp kernel.elf isodir/boot
	grub-mkrescue -o $@ isodir

run-qemu:
	qemu-system-i386 -cdrom phoenix.iso

%.o: %.c
	$(CC) $(CC_FLAGS) $^ -o $@

%.s.o: %.s
	$(ASM) -I$(ASMINCLUDE) $^ -o $@
