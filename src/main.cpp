#include "picovga.h"
#include "img/colourbars.h"
#include "img/colourgradients.h"
#include "img/circles.h"
#include "img/grid.h"
#include "lib/RP2040-Button/button.h"

#define WIDTH	320		// screen width
#define HEIGHT	240		// screen height

#define BUTTON_CYCLE_PATTERN 2

const u8* PatternArray[] = {
	Colour_Bars,
	Grid,
	Colour_Gradients,
	Circles
};
int PatternArraySize = 4;
int PatternIndex = 0;

ALIGNED u8 Framebuffer[320*240];

sCanvas PatternCanvas;

void button_onchange(button_t *button_p){
    button_t *button = (button_t*)button_p;
    if(button->state) return;

	PatternIndex = (PatternIndex + 1) % PatternArraySize;

	PatternCanvas.img = (u8*)PatternArray[PatternIndex];
	DrawImg(&Canvas, &PatternCanvas, 0, 0, 0, 0, WIDTH, HEIGHT);
}

int main()
{
	// Initialize video mode
	Video(DEV_NTSC, RES_QVGA, FORM_8BIT, Framebuffer);

	// Initialise pattern canvas
	PatternCanvas.img = (u8*)PatternArray[PatternIndex];
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
