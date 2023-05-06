#include "svdpi.h"
#include "VPC__Dpi.h"

extern "C" {
#include "../local-include/reg.h"
#include <generated/autoconf.h>
#include <sdb.h>
}

void write_r(const svLogicVecVal* no, const svLogicVecVal* val) {
	gpr(no->aval) = val->aval;
}