#include <iostream>
#include "ListItr.h"
#include <string>

/*
Caleb Lee
cjl2pub
9/10/2021
*/

ListItr::ListItr(){
  current = NULL;
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
  
}


bool ListItr::isPastEnd() const{
  if (current == NULL){
    return true;
  }
    return false;
  
}


bool ListItr::isPastBeginning() const{
  if(current == NULL){
    return true;
  }
  else{
    return false;
  }
}

void ListItr::moveForward(){
  current = current -> next;
}


int ListItr::retrieve() const{
  return current -> value;
}
