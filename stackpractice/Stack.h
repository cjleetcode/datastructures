#include <string>
#include <iostream>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"

#ifndef STACK_H
#define STACK_H

class Stack{

public:
  Stack();
  ~Stack();
  int top() const;
  void pop();
  void push(int i);
  bool empty() const;
  
private:
  ListNode* head;
};

#endif
