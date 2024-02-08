#include "picovga.h"
#include "img/colourbars.h"
#include "img/colourgradients.h"
#include "img/circles.h"
#include "img/grid.h"
#include "img/white.h"
#include "lib/RP2040-Button/button.h"
#include "pico/bootrom.h"

#include <chrono>

#define WIDTH	320		// screen width
#define HEIGHT	240		// screen height

#define GPIO_CYCLE_PATTERN 2

using sys_clock_t = std::chrono::high_resolution_clock;
using time_point_t = std::chrono::time_point<sys_clock_t>;
time_point_t buttonPressTime;

const u8* PatternArray[] = {
	Colour_Bars,
	Grid,
    White,
	Colour_Gradients,
	Circles
};
int PatternArraySize = 4;
int PatternIndex = 0;

ALIGNED u8 Framebuffer[320*240];

sCanvas PatternCanvas;

void initialise_pattern()
{
    // Initialise canvas
    PatternCanvas.img = (u8 *)PatternArray[PatternIndex];
    PatternCanvas.w = WIDTH;
    PatternCanvas.h = HEIGHT;
    PatternCanvas.wb = WIDTH;
    PatternCanvas.format = CANVAS_8;

    // Draw pattern
    DrawImg(&Canvas, &PatternCanvas, 0, 0, 0, 0, WIDTH, HEIGHT);
}

void draw_next_pattern()
{
    PatternIndex = (PatternIndex + 1) % PatternArraySize;
    PatternCanvas.img = (u8 *)PatternArray[PatternIndex];
    DrawImg(&Canvas, &PatternCanvas, 0, 0, 0, 0, WIDTH, HEIGHT);
}

void button_onchange(button_t *button_p){
    button_t *button = (button_t*)button_p;

    if (button->state) {
        // Button release
        // Calculate the duration of the button press
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(sys_clock_t::now() - buttonPressTime).count();

        if (duration >= 3) {
            // Reboot into BOOLSEL for flashing on long press
            reset_usb_boot(0,0);
        }

        return; // Ignore button release.
    }
    else {
        // Button press
        buttonPressTime = sys_clock_t::now();
    }

    draw_next_pattern();
}

int main()
{
	// Initialize video mode
	Video(DEV_NTSC, RES_QVGA, FORM_8BIT, Framebuffer);

    initialise_pattern();

    // Button handling
	create_button(GPIO_CYCLE_PATTERN, button_onchange);

	while (true)
	{
        sleep_ms(100);
	}
}