CROSS_TARGET=i686-elf

OBJS= _init.s.o kstring.o vga.o kernel.o

CC=$(CROSS_TARGET)-gcc
LD=$(CROSS_TARGET)-gcc
ASM=$(CROSS_TARGET)-as

INCLUDE=../include
LD_FILE=linker.ld

CC_FLAGS=-I$(INCLUDE) -Wall -Wextra -ffreestanding -std=gnu99
LD_FLAGS=-ffreestanding -nostdlib

.PHONY: all clean

all: $(OBJS)
	$(LD) -T $(LD_FILE) -o kernel.elf $(LD_FLAGS) $^ -lgcc

clean: 
	rm -fv $(OBJS)
	rm -fv kernel.elf

%.o: %.c
	$(CC) $(CC_FLAGS) $^ -o $@

%.s.o: %.s
	$(ASM) $^ -o $@
