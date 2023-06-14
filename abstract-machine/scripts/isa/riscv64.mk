ifneq ($(shell which riscv64-linux-gnu-gcc),)
CROSS_COMPILE := riscv64-linux-gnu-
else 
CROSS_COMPILE := riscv64-unknown-elf-
endif

COMMON_FLAGS  := -fno-pic -mcmodel=medany -mstrict-align -march=rv64g
CFLAGS        += $(COMMON_FLAGS) -static
ASFLAGS       += $(COMMON_FLAGS) 
LDFLAGS       += -melf64lriscv
