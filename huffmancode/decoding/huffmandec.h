#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "binary_node.h"

#ifndef HUFFMANDEC_H
#define HUFFMANDEC_H

using namespace std;

class huffmandec{

 public:
  huffmandec();
  void makeHuffNode(binary_node* n, char c, string dir);
  void decode(binary_node* n, string bits);
  binary_node* head;
};
#endif
