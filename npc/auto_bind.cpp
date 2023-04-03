#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->x, BIND_RATE_SCR, BIND_DIR_IN , 4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->en, BIND_RATE_SCR, BIND_DIR_IN , 1, SW4);
	nvboard_bind_pin( &top->y, BIND_RATE_SCR, BIND_DIR_OUT, 2, LD1, LD0);
}
