#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "List.h"
#include "ListItr.h"

int main(){

  List* a = new List();

 
  a -> insertAtTail(3);
  cout << (a-> head -> next) << endl;
 printList(*a, true);
	 return 0;
}
