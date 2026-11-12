# Test of the compilation with precompiled objects.
#
# Students get main.cc, test.hh, this Makefile and the object for their
# system (test.o.Linux64 or test.o.macOS), but not test.cc:
#
#   cp test.o.Linux64 test.o        (or: cp test.o.macOS test.o)
#   make run
#
# Teachers, with test.cc: "make objects" builds the object for this system.

# Compilation flags.
CXXFLAGS = -std=c++17 -Wall -Wno-unused-variable -fPIC -O3
LDFLAGS  = -std=c++11 -O3

# System, for the name of the precompiled object.
ifeq ($(shell uname -s),Linux)
	SYSTEM     = Linux64	
	ARCH_FLAGS =	
else
	SYSTEM     = macOS
	ARCH_FLAGS = -arch x86_64 -arch arm64
endif

all: main

main: main.o test.o
	$(CXX) $^ -o $@ $(LDFLAGS)

main.o: main.cc test.hh

run: main
	./main

# Clear error message when the precompiled object has not been copied.
ifeq ($(wildcard test.cc),)
test.o:
	$(error test.o not found: copy the object for your system, e.g. cp test.o.Linux64 test.o)
endif

# Only for teachers: builds the precompiled object for this system.
objects: test.cc test.hh
	$(CXX) $(CXXFLAGS) $(ARCH_FLAGS) -c test.cc -o test.o.$(SYSTEM)

# The precompiled object is kept when its source is not available.
PRECOMPILED = $(if $(wildcard test.cc),,test.o)

clean:
	rm -f main $(filter-out $(PRECOMPILED),$(wildcard *.o))

.PHONY: all run objects clean
