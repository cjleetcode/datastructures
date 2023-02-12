
# This is a comment                                                                                                     
#Caleb Lee Lab 104                                                                                                      

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings                                                                                
DEBUG=-g

OBJECTS = wordPuzzle.o timer.o hashTable.o


a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "hash table is ready."


wordPuzzle.o: wordPuzzle.cpp

timer.o: timer.h timer.cpp

hashTable.o: hashTable.h hashTable.cpp

.PHONY: clean
clean:
	-rm -f *.o hashMap

