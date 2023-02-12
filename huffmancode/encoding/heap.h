// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
// This code was adjusted to accompany vector<Node*> instead of vector<int>
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "binary_node.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<binary_node*> vec);
    ~heap();

    void insert(binary_node* b);
    binary_node* findMin();
    binary_node* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<binary_node*> heap2;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);

    friend class huffmanenc;
    friend class binary_node;
};

#endif
