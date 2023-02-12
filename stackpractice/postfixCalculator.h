#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include "Stack.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

class postfixCalculator{

 public:
  postfixCalculator();
  ~postfixCalculator();

  void add();
  void subtract();
  void multiply();
  void divide();
  void unNeg();
  void shove(int i);
  int tip();
  
 private:
  Stack nList;
 
};

#endif
