#include <string>
#include <iostream>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"

#ifndef STACK_H
#define STACK_H

class Stack{

public:
  stack();
  ~stack();
  int top();
  void pop();
  void push(int i);
  bool empty();
  
private:
  ListNode head;
}

#endif
