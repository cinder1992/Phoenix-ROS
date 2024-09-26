#include <platform/x86_64/platform.h>

void hcf(void) {
	while(1)
		asm("hlt");
}
