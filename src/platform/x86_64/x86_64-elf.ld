ENTRY(_start)

PHDRS
{
    requests PT_LOAD;
    text     PT_LOAD;
    rodata   PT_LOAD;
    data     PT_LOAD;
}

SECTIONS 
{
  . = 0xFFFFFFFF80000000;
  
  .requests : 
  {
	  KEEP(*(.requests.start))
	  KEEP(*(.requests))
	  KEEP(*(.requests.end))
  } :requests
  
  .text : ALIGN(CONSTANT(MAXPAGESIZE))
  {
    *(.text .text.*)
  } :text

  .rodata : ALIGN(CONSTANT(MAXPAGESIZE))
  {
    *(.rodata .rodata.*)
  } :rodata

  .data : ALIGN(CONSTANT(MAXPAGESIZE))
  {
    *(.data .data.*)
  } :data

  .bss :
  {
    *(.bss .bss.*)
    *(COMMON)
  } :data

  /DISCARD/ : {
	  *(.note .note.*)
	  *(.eh_frame*)
  }
}

