#Caleb Lee Lab 105 cjl2pub
#lab 11 prelab makefile

CXX= clang++
CXXFLAGS= -Wall -O3
DEBUG= $(CXXFLAGS) -g

OBJECTS= puzzle.o state_hash.o

a.out: $(OBJECTS)
	$(CXX) $(OBJECTS) $(DEBUG) -o a.out
	doxygen
	@echo "your puzzle is ready."

puzzle.o: puzzle.h puzzle.cpp pstate.h

state_hash.o: state_hash.cpp state_hash.h pstate.h

.PHONY: clean
clean:
	-rm -f *.o .cpp a.out
