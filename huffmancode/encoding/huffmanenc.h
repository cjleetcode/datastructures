#ifndef HUFFMANENC_H
#define HUFFMANENC_H

#include "binary_node.h"
#include "heap.h"
#include <string>
#include <iostream>

using namespace std;
class huffmanenc{
 public:
  huffmanenc();
  ~huffmanenc();
  void makeHuffTree();
  string bitPath(char c, binary_node* point);
  binary_node* findMin();
  void insert(binary_node* b);
  
  binary_node* head;
  
private:
  heap bh;

};

#endif
