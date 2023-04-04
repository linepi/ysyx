#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->clk, BIND_RATE_SCR, BIND_DIR_IN , 1, SW0);
	nvboard_bind_pin( &top->Q2, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD2);
	nvboard_bind_pin( &top->Q1, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD1);
	nvboard_bind_pin( &top->Q0, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD0);
}
