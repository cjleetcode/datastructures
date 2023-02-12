#lab 10 prelab makefile
#caleb lee, cjl2pub

CXX= clang++ $(CXXFLAGS)
CXXFLAGS = -Wall 
DEBUG = -g

OBJECTS= huffmandec.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "huffman code is ready."

huffmandec.o: huffmandec.h huffmandec.cpp binary_node.h


.PHONY: clean
clean:
	-rm -f *.o .cpp a.out
