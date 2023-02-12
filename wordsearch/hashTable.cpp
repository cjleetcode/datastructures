#include "hashTable.h"
#include <iostream>
#include <string>
#include <array>
#include <list>

using namespace std;

hashTable::hashTable(){
  stor = new list<string>[43920];
}

bool hashTable::find(string s){
  if(s.length() < 3){
    return false;
  }
  
  int hFunc = hashFunction(s);
  if(stor[hFunc].empty()){
    return false;
  }

  else{
    list <string> & sList = stor[hFunc];
    list<string>::iterator itrBegin = sList.begin();
    if(*itrBegin == s){
      return true;
    }
    
    for(list<string>::iterator itr = sList.begin(); itr != sList.end(); ++itr){
      if(*itr == s){
	return true;
      }
    }

    list<string>::iterator endItr = sList.end();
    if(*endItr == s){
      return true;
    }
    
    return false;
  }
}

int hashTable::hashFunction(string s){
  if(s.length() < 3)
    return 0;
  
  if(s.length() > 3){
    if(s.length() > 4)
      return int(s.at(0))*180 + int(s.at(1))*60 + int(s.at(2))*20 + int(s.at(3))*5 + int(s.at(4));
    else{
      return int(s.at(0))*180 + int(s.at(1))*60 + int(s.at(2))*20 + int(s.at(3))*5;
    }
  }

  return int(s.at(0))*180 + int(s.at(1))*60 + int(s.at(2))*20;
}

void hashTable::insert(string s){
  
  int i = hashFunction(s);
  stor[i].push_back(s);

}
