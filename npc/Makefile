NBNAME = nb
VERNAME = ver
TESTNAME = testbench
OBJ_DIR = obj_dir
NXDC_FILES = vsrc/$(NBNAME).nxdc
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc --timing \
				# -O3 --x-assign fast --x-initial fast --noassert

# constraint file
SRC_AUTO_BIND = auto_bind.cpp
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
INC_PATH ?=
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
NB_CSRCS = $(filter-out %ver.cpp, $(CSRCS))
VER_CSRCS = $(filter-out %nb.cpp %$(SRC_AUTO_BIND), $(CSRCS))
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk
# rules for ysyx
include ../Makefile

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(NBNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(NBNAME): $(VSRCS) $(NB_CSRCS) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(NBNAME) $^ \
		$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--exe -o $(abspath $(NBNAME))
	$(abspath $(NBNAME))
	-@rm -rf obj_dir auto_bind.cpp

# just for the simulator of verilator
$(VERNAME): $(VSRCS) $(VER_CSRCS)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(VERNAME) $^ \
		--exe -o $(abspath $(VERNAME))
	$(abspath $(VERNAME))
	-@rm -rf obj_dir

# just for testbench of verilator
$(TESTNAME): $(VSRCS)
	$(VERILATOR) --binary --timing \
		--top-module $(TESTNAME) $^ \
		-o $(abspath $(TESTNAME))
	$(abspath $(TESTNAME))
	-@rm -rf obj_dir

clean:
	-@rm -rf obj_dir auto_bind.cpp $(NBNAME) $(VERNAME) $(TESTNAME)

.PHONY: clean $(NBNAME) $(VERNAME) $(TESTNAME) 

