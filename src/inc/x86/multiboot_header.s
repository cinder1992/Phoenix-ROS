# Declare multiboot constants
# TODO: Change to Multiboot2 spec
.set ALIGN,   1<<0
.set MEMINFO, 1<<1
.set MODESET, 1<<2
.set FLAGS,   ALIGN | MEMINFO | MODESET
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)
.set MODE_TYPE, 1
.set WIDTH, 80
.set HEIGHT, 25
.set DEPTH, 0

#Declare the multiboot section
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
.skip 20
.long MODE_TYPE
.long WIDTH
.long HEIGHT
.long DEPTH
