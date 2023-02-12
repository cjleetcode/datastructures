// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
// This code was adjusted to accompany vector<Node*> instead of vector<int>
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include "binary_node.h"
using namespace std;

class binary_heap {
public:
    binary_heap();
    binary_heap(vector<binary_node*> vec);
    ~binary_heap();

    void insert(binary_node* b);
    binary_node* findMin();
    binary_node* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<binary_node*> heap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);

    friend class huffmanenc;
  friend class binary_node;
};

#endif
