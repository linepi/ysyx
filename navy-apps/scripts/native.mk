LD = $(CXX)

### Run an application with $(ISA)=native

env:
	@$(MAKE) -C $(NAVY_HOME)/libs/libos ISA=native

run: app
ifeq ($(shell uname),Darwin)
	$(APP) $(mainargs)
else
	LD_PRELOAD=$(NAVY_HOME)/libs/libos/build/native.so $(APP) $(mainargs)
endif

gdb: app
ifeq ($(shell uname),Darwin)
	lldb -- $(APP) $(mainargs) 
else
	gdb -ex "set environment LD_PRELOAD $(NAVY_HOME)/libs/libos/build/native.so" --args $(APP) $(mainargs)
endif

.PHONY: env run gdb
