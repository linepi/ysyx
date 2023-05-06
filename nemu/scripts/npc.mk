NPC_CSRCS = $(shell find $(NEMU_HOME)/src/isa/riscv64/npc -name "*.cc")
NPC_VSRCS = $(shell find $(NPC_HOME)/vsrc/common $(NPC_HOME)/vsrc/LemonPC -name "*.v")

VERILATOR = verilator
VERILATOR_FLAGS += -MMD --build -cc --timing -O3 --x-assign fast --x-initial fast --noassert

INC_PATH += $(NEMU_HOME)/src/isa/riscv64/npc

