
#include "picovga.h"

// EGA (512x400) frame buffer for display
ALIGNED u8 Framebuffer[512*400];

int main()
{
	// Initialize video mode
	Video(DEV_VGA, RES_EGA, FORM_8BIT, Framebuffer);

	// Draw text
	DrawText(&Canvas, "Hello World!", (512-12*8*4)/2, (400-8*4)/2,
		COL_WHITE, FontBoldB8x16, 16, 4, 4);
}
