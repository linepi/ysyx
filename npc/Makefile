all:
	@echo
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall vsrc/our.v csrc/sim_main.cpp --cc --trace --exe --build

include ../Makefile
