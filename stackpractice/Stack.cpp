#include <iostream>
#include <string>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
#include "Stack.h"

Stack::Stack(){
  head = new ListNode();
}

Stack::~Stack(){

}

int Stack::top() const{
  ListItr tip(head);
  if(tip.isPastBeginning() || tip.isPastEnd() || tip.current == NULL){
    return -1;
  }
  while(tip.current -> next != NULL){
  tip.moveForward();
  }
  return tip.retrieve();
}

void Stack::pop(){
  if(head -> next  == NULL){
    return;
  }

  ListItr check(head);
    while(check.current -> next -> next != NULL){
    check.moveForward();
  }
    check.current -> next = NULL;
    
}

void Stack::push(int i){
  ListNode* a = new ListNode();
  a -> value = i;

  if(head -> next == NULL)
    head -> next = a;
  
  ListItr check(head -> next);
  while(check.current -> next != NULL){
    check.moveForward();
  }
  check.current -> next = a;
  a -> next = NULL;
}

bool Stack::empty() const{
  return head -> next == NULL;
}
