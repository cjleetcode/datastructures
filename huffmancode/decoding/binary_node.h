#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <iostream>
#include <string>
using namespace std;

class binary_node{

public:
  binary_node* left;
  binary_node* right;
  int freq;
  char ID;
 private:
  friend class binary_heap;
  friend class binary_node;
  friend class huffmandec;
};

#endif

