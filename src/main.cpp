#include "picovga.h"
#include "img/monoscope.h"

#define WIDTH	320		// screen width
#define HEIGHT	240		// screen height

ALIGNED u8 Framebuffer[320*240];

sCanvas PatternCanvas;

int main()
{
	// Initialize video mode
	Video(DEV_NTSC, RES_QVGA, FORM_8BIT, Framebuffer);

	// Initialise pattern canvas
	PatternCanvas.img = (u8*)Monoscope;
	PatternCanvas.w = WIDTH;
	PatternCanvas.h = HEIGHT;
	PatternCanvas.wb = WIDTH;
	PatternCanvas.format = CANVAS_8;

	// Draw pattern
	DrawImg(&Canvas, &PatternCanvas, 0, 0, 0, 0, WIDTH, HEIGHT);
}
