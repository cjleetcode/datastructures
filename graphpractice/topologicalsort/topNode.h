#ifndef TOPNODE_H
#define TOPNODE_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
class topNode{
 public:
  topNode* previous;
  topNode* next;
  string ID;
  int indegree;

 private:
  friend class topological;
};

#endif
