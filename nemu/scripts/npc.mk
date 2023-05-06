VERILATOR = verilator
VERILATOR_FLAGS += -MMD --build -cc --timing -O3 --x-assign fast --x-initial fast --noassert

# for verilator source file
VERILATOR_INC_PATH = $(VERILATOR_ROOT)/include $(VERILATOR_ROOT)/include/vltstd .
VERILATOR_CFLAGS = -MMD -Os -DVM_COVERAGE=0 -DVM_SC=0 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 \
	-faligned-new -fcf-protection=none \
	-Wno-bool-operation -Wno-sign-compare -Wno-uninitialized -Wno-unused-but-set-variable \
	-Wno-unused-parameter -Wno-unused-variable -Wno-shadow
VERILATOR_CSRCS = verilated.cpp verilated_threads.cpp verilated_dpi.cpp
VERILATOR_CSRCS := $(addprefix $(VERILATOR_ROOT)/, $(VERILATOR_CSRCS))
VERILATOR_OBJS = $(patsubst %.cpp, %.o, $(addprefix $(NPC_OBJ_DIR)/, $(notdir $(VERILATOR_CSRCS))))
VERILATOR_CFLAGS += $(addprefix -I, $(VERILATOR_INC_PATH))

NPC_CSRCS = $(shell find $(NEMU_HOME)/src/isa/riscv64/npc -name "*.cc")
NPC_VSRCS = $(shell find $(NPC_HOME)/vsrc/common $(NPC_HOME)/vsrc/LemonPC -name "*.v")
NPC_INC_PATH += $(NEMU_HOME)/src/isa/riscv64/npc $(NEMU_HOME)/src/isa/riscv64/npc/obj_dir 
NPC_INCFLAGS = $(addprefix -I, $(NPC_INC_PATH) $(VERILATOR_INC_PATH))

NPC_OBJ_DIR = $(NEMU_HOME)/src/isa/riscv64/npc/obj_dir
NPC_OBJS = $(patsubst %.cc, %.o, $(addprefix $(NPC_OBJ_DIR)/, $(notdir $(NPC_CSRCS))))
NPC_CFLAGS += $(NPC_INCFLAGS) $(CFLAGS)

# NPC_ARCHIVE = $(NPC_OBJ_DIR)/npc.a
# ARCHIVES += $(NPC_ARCHIVE)

# $(NPC_ARCHIVE): $(NPC_OBJ_DIR)/VPC__ALL.o $(NPC_OBJS) $(VERILATOR_OBJS)
# 	ar -rcs $@ $^
OBJS += $(NPC_OBJS) $(VERILATOR_OBJS) $(NPC_OBJ_DIR)/VPC__ALL.o

$(NPC_OBJ_DIR)/VPC__ALL.o: $(NPC_VSRCS)
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module PC $^ \
	--Mdir $(NPC_OBJ_DIR)

$(NPC_OBJS):$(NPC_OBJ_DIR)/%.o:$(NEMU_HOME)/src/isa/riscv64/npc/%.cc
	$(CXX) $(NPC_CFLAGS) -c -o $@ $<

$(VERILATOR_OBJS):$(NPC_OBJ_DIR)/%.o:$(VERILATOR_ROOT)/include/%.cpp
	$(CXX) $(VERILATOR_CFLAGS) -c -o $@ $<