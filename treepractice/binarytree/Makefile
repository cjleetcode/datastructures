# This is a comment
#Caleb Lee Lab 104

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

OBJECTS = TreeCalc.o TreeCalcTest.o TreeNode.o


a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "tree is ready."


objects.o: TreeNode.o TreeCalc.o TreeCalcTest.o

TreeNode.o: TreeNode.cpp TreeNode.h

TreeCalc.o: TreeCalc.cpp TreeCalc.h

TreeCalcTest.o: TreeCalcTest.cpp

.PHONY: clean
clean:
	-rm -f *.o tree
