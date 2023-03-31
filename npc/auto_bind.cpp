#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->a, BIND_RATE_RT , BIND_DIR_OUT, 1, VGA_VSYNC);
	nvboard_bind_pin( &top->b, BIND_RATE_RT , BIND_DIR_OUT, 1, VGA_HSYNC);
	nvboard_bind_pin( &top->f, BIND_RATE_RT , BIND_DIR_OUT, 1, VGA_BLANK_N);
}
