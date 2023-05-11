VERILATOR = verilator
VERILATOR_FLAGS += -MMD --build -cc -O2 --timing --x-assign fast --x-initial fast --noassert
VERILATOR_FLAGS += -I$(NPC_HOME)/vsrc/LemonPC

# for verilator source file
VERILATOR_INC_PATH = $(VERILATOR_ROOT)/include $(VERILATOR_ROOT)/include/vltstd .
VERILATOR_CFLAGS = -MMD -O2 -g -DVM_COVERAGE=0 -DVM_SC=0 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 \
	-faligned-new -fcf-protection=none -fcoroutines \
	-Wno-bool-operation -Wno-sign-compare -Wno-uninitialized -Wno-unused-but-set-variable \
	-Wno-unused-parameter -Wno-unused-variable -Wno-shadow
VERILATOR_CSRCS = verilated.cpp verilated_dpi.cpp verilated_timing.cpp verilated_threads.cpp 
VERILATOR_CSRCS := $(addprefix $(VERILATOR_ROOT)/, $(VERILATOR_CSRCS))
VERILATOR_OBJS = $(patsubst %.cpp, %.o, $(addprefix $(NPC_OBJ_DIR)/, $(notdir $(VERILATOR_CSRCS))))
VERILATOR_CFLAGS += $(addprefix -I, $(VERILATOR_INC_PATH))

NPC_CSRCS = $(shell find $(NEMU_HOME)/src/isa/riscv64/npc -name "*.cc")
NPC_VSRCS = $(shell find $(NPC_HOME)/vsrc/common $(NPC_HOME)/vsrc/LemonPC -name "*.v")
NPC_INC_PATH += $(NEMU_HOME)/src/isa/riscv64/npc/obj_dir 
NPC_INCFLAGS = $(addprefix -I, $(NPC_INC_PATH) $(VERILATOR_INC_PATH))

NPC_OBJ_DIR = $(NEMU_HOME)/src/isa/riscv64/npc/obj_dir
NPC_OBJS = $(patsubst %.cc, %.o, $(addprefix $(NPC_OBJ_DIR)/, $(notdir $(NPC_CSRCS))))
NPC_CFLAGS += $(NPC_INCFLAGS) $(CFLAGS) 

$(NPC_OBJ_DIR)/VPC__ALL.o: $(NPC_VSRCS)
	@echo "+ CC $(notdir $@)"
	@$(VERILATOR) $(VERILATOR_FLAGS) --top-module PC $^ \
	--Mdir $(NPC_OBJ_DIR)

$(NPC_OBJS):$(NPC_OBJ_DIR)/%.o:$(NEMU_HOME)/src/isa/riscv64/npc/%.cc
	@echo "+ CC $(notdir $@)"
	@$(CXX) $(NPC_CFLAGS) -c -o $@ $<

$(VERILATOR_OBJS):$(NPC_OBJ_DIR)/%.o:$(VERILATOR_ROOT)/include/%.cpp
	@echo "+ CC $(notdir $@)"
	@g++ $(VERILATOR_CFLAGS) -c -o $@ $<