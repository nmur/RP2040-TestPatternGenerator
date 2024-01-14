
#include "picovga.h"

ALIGNED u8 Framebuffer[320*240];

int main()
{
	// Initialize video mode
	Video(DEV_NTSC, RES_QVGA, FORM_8BIT, Framebuffer);

	// Draw text
	DrawText(&Canvas, "Hello World!", (320-12*8*4)/2, (240-8*4)/2, COL_WHITE, FontBoldB8x16, 16, 4, 4);
}
