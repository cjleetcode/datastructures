#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include <string>

/*
Caleb Lee
cjl2pub
List.cpp
09/10/2021
*/

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(){
  count = 0;
  head = new ListNode();
  head ->next = NULL;
}

List::List(const List& source) {
    head=new ListNode();
    head->next= NULL;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        iter.moveForward();
    }
}

List::~List(){
  this -> makeEmpty();
  delete head;
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

void List::insertAtTail(int x){
}


ListItr List::first(){
  ListItr henlo(head -> next);
  if(henlo.isPastEnd() || henlo.isPastBeginning())
    henlo.current = head -> next;
  return henlo;
}

bool List::isEmpty() const{
  if(head == NULL)
    return true;
  if(head -> next != NULL)
    return false;
  return true;
}

void List::makeEmpty(){
  ListItr hed(head);

  if(this -> size() == 0)
    return;
  
  while(!hed.isPastEnd()){
    hed.moveForward();
    hed.current = NULL;
  }

  head -> next = NULL;
  delete head;
}

ListItr List::last(){
  ListItr henla(head -> next);
  if(henla.isPastBeginning() || henla.isPastEnd())
    henla.current = head;
  return henla;
}

void List::insertAfter(int x, ListItr position){
  ListNode* heehee = new ListNode();
  
  if(position.isPastEnd()){
    cout << "too far back" << endl;
    position.current = head;
  }

  else{
    position.current -> next = heehee;
  }
}


void List::insertBefore(int x, ListItr position){

}

ListItr List::find(int x){
  ListNode* daNode = new ListNode();
  daNode = head;
  ListItr no(daNode);
  while(!no.isPastEnd()){
    if(no.current -> value == x)
      return no;
    no.moveForward();
  }
  return NULL;
}



int List::size() const{
  int count2 = -1;
  ListItr boom(head);
  while(!boom.isPastEnd()){
    count2++;
    boom.moveForward();
  }
  return count2;
}

void List::remove(int x){

}

void printList(List& source, bool forward){
 
      if(forward){
	if(source.isEmpty())
	  cout << "empty!" << endl;

	ListItr fIter(source.first());
	while(fIter.isPastEnd() != true){
	  cout << fIter.retrieve()  << " " << endl;
	 fIter.moveForward();
	}
      }
      
    
}
