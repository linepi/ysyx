NBNAME = nb
VERNAME = ver
TESTNAME = testbench
PCNAME = LemonPC

OBJ_DIR = obj_dir
NXDC_FILES = vsrc/nb/$(NBNAME).nxdc
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc --timing -O3 --x-assign fast --x-initial fast --noassert

# constraint file
SRC_AUTO_BIND = auto_bind.cpp
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
INC_PATH += $(NPC_HOME)/csrc/include 
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

PC_CSRCS = $(filter-out %nb.cpp %ver.cpp %$(SRC_AUTO_BIND), $(CSRCS))
PC_VSRCS = $(shell find $(abspath ./vsrc/LemonPC) $(abspath ./vsrc/common) -name "*.v")
NB_CSRCS = $(filter-out %ver.cpp $(PC_CSRCS), $(CSRCS))
NB_VSRCS = $(shell find $(abspath ./vsrc/nb) $(abspath ./vsrc/common) -name "*.v")
VER_CSRCS = $(filter-out %nb.cpp $(PC_CSRCS) %$(SRC_AUTO_BIND), $(CSRCS))
VER_VSRCS = $(shell find $(abspath ./vsrc/ver) $(abspath ./vsrc/common) -name "*.v")
TEST_VSRCS = $(shell find $(abspath ./vsrc/common) -name "*.v") vsrc/$(TESTNAME).v
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk
# rules for ysyx
include ../Makefile

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(NBNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(NBNAME): $(NB_VSRCS) $(NB_CSRCS) $(NVBOARD_ARCHIVE)
	$(call git_commit, "build nvboard") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(NBNAME) $^ \
		$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--exe -o $(abspath $(NBNAME))
	$(abspath $(NBNAME))

# just for the simulator of verilator
$(VERNAME): $(VER_VSRCS) $(VER_CSRCS)
	$(call git_commit, "build ver") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(VERNAME) \
		$(addprefix -CFLAGS , $(INCFLAGS)) $^ \
		--exe -o $(abspath $(VERNAME))
	$(abspath $(VERNAME))

$(PCNAME): $(PC_VSRCS) $(PC_CSRCS)
	$(call git_commit, "build npc") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module PC \
		$(addprefix -CFLAGS , $(INCFLAGS)) $^ \
		--exe -o $(abspath '$(PCNAME)')
	$(abspath $(PCNAME))

# just for testbench of verilator
$(TESTNAME): $(TEST_VSRCS)
	$(call git_commit, "build testbench") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) --binary --timing -I. \
		--top-module $(TESTNAME) $^ \
		-o $(abspath $(TESTNAME))
	$(abspath $(TESTNAME))

clean:
	-@rm -rf obj_dir auto_bind.cpp $(NBNAME) $(VERNAME) $(TESTNAME) $(PCNAME)

.PHONY: clean $(NBNAME) $(VERNAME) $(TESTNAME) 

