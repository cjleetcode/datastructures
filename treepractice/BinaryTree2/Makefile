#Caleb Lee lab 104

CXX= clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -O2
DEBUG = -g

OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.cpp

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "tree2 is ready."


BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h

.PHONY: clean
clean:
	-rm -f *.o .cpp tree2
