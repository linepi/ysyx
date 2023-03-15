all:
	@echo Hello
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall vsrc/our.v csrc/sim_main.cpp --cc --trace --exe --build

include ../Makefile

clean:
	-rm -f wave.vcd
	-rm -rf obj_dir

.PHONY: clean sim all