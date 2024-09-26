#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <platform.h>
#include <limine.h>
#define limine_request_base(s) \
	__attribute__((used, section(#s))) static volatile
#define limine_start_marker \
	limine_request_base(.requests.start) LIMINE_REQUESTS_START_MARKER
#define limine_end_marker \
	limine_request_base(.requests.end) LIMINE_REQUESTS_END_MARKER
#define limine_request \
	limine_request_base(.requests)

limine_start_marker;
limine_request LIMINE_BASE_REVISION(2);
limine_request struct limine_framebuffer_request framebuffer_request = {
	.id = LIMINE_FRAMEBUFFER_REQUEST,
	.revision = 0
};
limine_end_marker;

void _start(void) {
	//code borrowed from Limine barebones
	// Ensure the bootloader actually understands our base revision (see spec).
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        hcf();
    }

    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }

    // Fetch the first framebuffer.
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    // Note: we assume the framebuffer model is RGB with 32-bit pixels.
    for (size_t i = 0; i < 100; i++) {
        volatile uint32_t *fb_ptr = framebuffer->address;
        fb_ptr[i * (framebuffer->pitch / 4) + i] = 0xffffff;
    }

    // We're done, just hang...
    hcf();

}
