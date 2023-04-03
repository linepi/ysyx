TOPNAME = top
TESTNAME = testbench
BIN = $(TOPNAME)
NXDC_FILES = vsrc/$(TOPNAME).nxdc
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
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk
# rules for ysyx
include ../Makefile

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--exe -o $(abspath $(BIN))

nb: $(BIN)
	$(abspath $^)
	-rm -rf obj_dir $(BIN) auto_bind.cpp

test: 
	$(VERILATOR) --binary --timing vsrc/testbench.v --top-module testbench -o $(abspath $(TESTNAME))
	-rm -rf obj_dir $(TESTNAME)

clean:
	-rm -rf obj_dir $(BIN) auto_bind.cpp

.PHONY: clean default nb com

