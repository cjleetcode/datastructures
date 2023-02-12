#include <string>
#include <iostream>

#ifndef STACKNODE_H
#define STACKNODE_H

/*
Caleb Lee
cjl2pub
CS 2150
9/15/2021
 */
class stackNode{

 public:
  stackNode();
  ~stackode();

 private:
  int value;
  stackNode* next;
}
