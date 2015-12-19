# Declare multiboot constants
# TODO: Change to Multiboot2 spec
.set ALIGN,   1<<0
.set MEMINFO. 1<<1
.set FLAGS,   ALIGN | MEMINFO
.set MAGIC    0x1BADBOO2
.set CHECKSUM -(MAGIC + FLAGS)

#Declare the multiboot section
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

#Declare a 16k initial stack
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384
stack_top:

#Declare our code segment and entry vector
.section .text
.global _start
.type _start, @function

_start:
  movl $stack_top, %esp #Set up the stack we created earlier
  call kernel_main  #Call the C-code for our kernel

  cli #Jump into an inifinite loop should our kernel_main return
  hlt
.Lhang:
  jmp .Lhang

.size _start, . - _start #Set the size of the symbol.

