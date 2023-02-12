#Caleb Lee lab 104

CXX= clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -O2
DEBUG = -g

OBJECTS = AVLNode.o AVLPathTest.o AVLTree.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "tree3 is ready."

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h


.PHONY: clean
clean:
	-rm -f *.o .cpp a.out
