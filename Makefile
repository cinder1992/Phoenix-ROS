CROSS_TARGET = i686_elf

.PHONY: clean run-qemu

clean:
	rm -fvr isodir
	rm -fv phoenix.iso
	$(MAKE) -C src clean

kernel.elf:
	$(MAKE) -C src

phoenix.iso: 
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub
	cp src/kernel.elf isodir/boot
	grub-mkrescue -o $@ isodir

run-qemu:
	qemu-system-i386 -cdrom phoenix.iso 

