ifeq ($(ISA), native)

ifeq ($(shell uname),Darwin)
NATIVE_FILE = src/native_osx.c
NATIVE_DY = build/native.dylib
$(NATIVE_DY): $(NATIVE_FILE)
	@mkdir -p build/
	clang -O1 -fpic -shared -g -o $(realpath $@) $^ -ldl -lSDL2
else
NATIVE_FILE = src/native.cpp
NATIVE_DY = build/native.so
$(NATIVE_DY): $(NATIVE_FILE)
	@mkdir -p build/
	g++ -std=c++11 -O1 -fPIC -shared -g -o $@ $^ -ldl -lSDL2
endif

else
NAME = libos
SRCS = src/syscall.c src/crt0/crt0.c src/crt0/start/$(ISA).S
include $(NAVY_HOME)/Makefile
endif
