// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
// This code has been adjusted to fit the needs of a vector of trees, not ints
#include <iostream>
#include "binary_node.h"
#include "heap.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    heap2.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<binary_node*> vec) : heap_size(vec.size()) {
    heap2 = vec;
    heap2.push_back(heap2[0]);
    heap2[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(binary_node* b) {
    // a vector push_back will resize as necessary
    heap2.push_back(b);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    binary_node* x = heap2[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x -> freq < (heap2[hole/2] -> freq)); hole /= 2) {
        heap2[hole] = heap2[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heap2[hole] = x;
}

binary_node* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    binary_node* ret = heap2[1];
    // move the last inserted position into the root
    heap2[1] = heap2[heap_size--];
    // make sure the vector knows that there is one less element
    heap2.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    binary_node* x = heap2[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heap2[child+1] -> freq < heap2[child] -> freq)) {
            child++;
        }
        // if the child is greater than the node...
        if (x -> freq > heap2[child] -> freq) {
            heap2[hole] = heap2[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heap2[hole] = x;
}

binary_node* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heap2[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heap2.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(0) ";
    for (int i = 1; i <= heap_size; i++) {
        cout << heap2[i] -> ID << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}
