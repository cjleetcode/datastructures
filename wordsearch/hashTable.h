#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <array>
#include <list>

using namespace std;

class hashTable{
public:
  hashTable();
  bool find(string s);
  void insert(string s);
  int hashFunction(string s);
  
private:
  list <string>* stor;

};

#endif

