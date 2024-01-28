#include "picovga.h"
#include "img/monoscope.h"
#include "lib/RP2040-Button/button.h"

#define WIDTH	320		// screen width
#define HEIGHT	240		// screen height

#define BUTTON_CYCLE_PATTERN 2

ALIGNED u8 Framebuffer[320*240];

sCanvas PatternCanvas;

void button_onchange(button_t *button_p){
    button_t *button = (button_t*)button_p;
    if(button->state) return;

    DrawText(&Canvas, "Button Press!", (512-12*8*4)/2, (400-8*4)/2, COL_WHITE, FontBoldB8x16, 16, 4, 4);
}

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

	// Button handling
    create_button(BUTTON_CYCLE_PATTERN, button_onchange);

	while (true)
	{
        sleep_ms(100);
	}
}
