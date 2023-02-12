#include "postfixCalculator.h"
#include "Stack.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include <iostream>
#include <string>

using namespace std;

postfixCalculator::postfixCalculator(){
}

postfixCalculator::~postfixCalculator(){
}

void postfixCalculator::add(){

  int i1 = 0;
  int i2 = 0;

  if(nList.empty()){
	i1 = nList.top();
      }
      else{
	i2 = nList.top();
	nList.pop();
	i1 = nList.top();
	nList.push(i2);
      }
      nList.pop();
      nList.pop();
      nList.push(i1 + i2);

}

void postfixCalculator::subtract(){
 
  int i1 = 0;
  int i2 = 0;
  
  if(nList.empty()){
	i1 = nList.top();
      }
      else{
	i2 = nList.top();
	nList.pop();
	i1 = nList.top();
	nList.push(i2);
      }
      nList.pop();
      nList.pop();
      nList.push(i1 - i2);
}

void postfixCalculator::multiply(){

  int i1 = 0;
  int i2 = 0;
  
  if(nList.empty()){
	i1 = nList.top();
      }
      else{
	i2 = nList.top();
	nList.pop();
	i1 = nList.top();
	nList.push(i2);
      }
      nList.pop();
      nList.pop();
      nList.push(i1 * i2);
}

void postfixCalculator::divide(){

  int i1 = 0;
  int i2 = 0;
  
  if(nList.empty()){
	i1 = nList.top();
      }
      else{
	i2 = nList.top();
	nList.pop();
	i1 = nList.top();
	nList.push(i2);
      }
      nList.pop();
      nList.pop();
      nList.push(i1 / i2);
}

void postfixCalculator::unNeg(){
  int i1 = nList.top();
  nList.pop();
  nList.push(-i1);
}
void postfixCalculator::shove(int i){
  nList.push(i);
}

int postfixCalculator::tip(){
  if(!nList.empty())
  return nList.top();
  else{
    cout << "nothing here!" << endl;
    return 0;
  }
}
