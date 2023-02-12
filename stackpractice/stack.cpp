#include <iostream>
#include <string>
#include "List.cpp"
#include "ListItr.cpp"
#include "ListNode.cpp"

stack::stack(){
  head = new ListNode();
}

stack::~stack(){

}

int stack::top(){
  ListItr tip(head);
  if(tip -> isPastBeginning() || tip -> isPastEnd()){
    cout << "past the list ends" << endl;
    return -1;
  }
  while(tip -> next != NULL){
  tip -> moveForward();
  }
  return tip -> retrieve();
}

void stack::pop(){
  if(numList -> isEmpty()){
    cout << "can't pop; nothing is here" << endl;
    return;
  }
  
  list -> tail -> previous -> previous = NULL;
  
}

void stack::push(int i){
  ListNode* a = new ListNode();
  a -> value = i;
  list -> insertAtTail(a);
}

bool stack::empty(){
  return numList -> isEmpty();
}
