//Caleb Lee Lab 105 CS 2150 cjl2pub
//to the TA looking over this: i'm already in winter break mode lmao

#ifndef TOPOLOGICAL_H
#define TOPOLOGICAL_H

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>

using namespace std;

class topological{
 public:
  topological();
  ~topological();
  /**
   * @brief creates the graph.
   *
   * @param s1 the first string to be used as the Id for a vertex pointing to s2.
   * @param s2 the second string to be used as the ID for another vertex.
   */
  void makeNest(string s1, string s2);
  /**
   * @brief creates another vector, but only for the indegrees of each node.
   * @details this code assumes that a valid nest has been made and stored in nest.
   * the code will iterate through -nest-, a vector of vector of vertices, and determine
   * the indegrees of each node that stems from a "head node", or the source of a sub-branch,
   * and this will happen until the program is done and all values are calculated.
   */
  void findIn();
  /**
   * @brief print out the topological sort given the indegrees
   */
  void topologicalSort();
  /**
   * @brief auxilary methods to traverse Ndegree and nest, respectively. Won't be used in main().
   */
  void traverseV();
  void traverseNest();
 private:
  vector<vector<topNode*>> nest;
  vector<topNode*> Ndegree;
  queue<topNode*> q;
  friend class topNode;
};
#endif
