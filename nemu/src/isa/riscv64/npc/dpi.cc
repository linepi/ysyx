#include "svdpi.h"
#include "VPC__Dpi.h"

extern "C" {
#include "../local-include/reg.h"
#include <generated/autoconf.h>
#include <sdb.h>
}

void write_r(int no, uint64_t val) { 
	gpr(no) = val;
}