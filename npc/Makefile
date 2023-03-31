TOPNAME = a
NXDC_FILES = $(TOPNAME).nxdc

default: sim
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall vsrc/top.v csrc/sim_main.cpp --cc --trace --exe --build
	@echo $(NXDC_FILES)

include ../Makefile
clean:
	-rm -rf obj_dir wave_vcd

.PHONY: clean sim default

