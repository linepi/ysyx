ifneq ($(shell which riscv64-linux-gnu-gcc),)
CROSS_COMPILE := riscv64-linux-gnu-
else 
CROSS_COMPILE := riscv64-unknown-elf-
endif
LNK_ADDR = $(if $(VME), 0x40000000, 0x83000000)
CFLAGS  += -fno-pic -march=rv64g -mcmodel=medany 
LDFLAGS += --no-relax -Ttext-segment $(LNK_ADDR)
