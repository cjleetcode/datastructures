#include "topNode.h"
#include "topological.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstdlib>
#include <list>

using namespace std;

//make the graph; s1 goes into s2
topological::topological(){

}

topological::~topological(){

}

void topological::makeNest(string s1, string s2){
  int i = 0;
  int j = 0;
  topNode* n1 = new topNode();
  topNode* n2 = new topNode();

  n1 -> ID = s1;
  n2 -> ID = s2;

  if(nest.size() == 0){
     vector<topNode*> v;
     v.push_back(n1);
     v.push_back(n2);
     nest.push_back(v);
     return;
  }
  
  while(i < nest.size()){//D
    //either insert new element into bucket or terminate if it already exists
    if(nest[i][j] -> ID == n1 -> ID){//C
      while(j < nest[i].size()){//A
	//checks for vertices already inserted
	if(nest[i][j] -> ID == n2 -> ID){//B
	  return;
	}//B
	j++;
      }//A; if this part runs it means no duplicates were found
      nest[i].push_back(n2);
      return;
    }//C
    j = 0;
    i++;
  }//d
  //new n1 detected
  i--;
  vector<topNode*> v;
  v.push_back(n1);
  v.push_back(n2);
  nest.push_back(v);
}

void topological::findIn(){
  int i1 = 0;
  int j1 = 0;
  int k1 = 0;
  string check = "";
  
  while(i1 < nest.size()){//B
    //if Ndegree is empty, put the first element 
    if(Ndegree.size() == 0){//A
      topNode* n1 = new topNode();
      n1 -> ID = nest[0][0] -> ID;
      n1 -> indegree = 0;
      Ndegree.push_back(n1);
    }//A

     //either increment each indegree by 1 if it's found or make a new one with indegree 1
    //or 0 if it's the first one in the list
    while(j1 < nest[i1].size()){//C
      
      //check if node exists, and if it does, increment
      while(k1 < Ndegree.size()){//ee
	if(nest[i1][j1] -> ID == Ndegree[k1] -> ID){
	  //if start of nest, no increment needed since it points to a node, not from one
	  if(j1 != 0)
	    (Ndegree[k1] -> indegree)++;
	  k1 = 0;
	  break;
	}
        
	//no such node with that string exists, so make a new one
	if(k1 + 1 == Ndegree.size()){//e
	  topNode* n2 = new topNode();
	  n2 -> ID = nest[i1][j1] -> ID;
	  if(j1 == 0)
	    n2 -> indegree = 0;
	  else
	    n2 -> indegree = 1;
	  Ndegree.push_back(n2);
	  k1 = 0;
	  break;
	}//e
	k1++;
      }//ee k1 <= Ndegree size
      k1 = 0;
      j1++;
    }//C j1 < nest[i1] size
    j1 = 0;
    i1++;
    k1 = 0;
  }//B i1 < nest size
  
}

//code inspired from slide 11 set: 5-8. topNode = vertices.
//this code is VERY inefficient, i know.
void topological::topologicalSort(){
  topNode* v, w;
  string s, index;
  int i2 = 0;
  int j2 = 1;
  int k2 = 0;
  while(i2 < Ndegree.size()){
    if(Ndegree[i2] -> indegree == 0){
      q.push(Ndegree[i2]);
      Ndegree.erase(Ndegree.begin() + i2);
      i2--;
    }
    i2++;
  }

  i2 = 0;
  
  while(!q.empty()){//g
    v = q.front();
    q.pop();
    cout << v -> ID << " ";
    s = v -> ID;
    while(i2 < nest.size()){//f
      if(s == nest[i2][0] -> ID){//e
	while(j2 < nest[i2].size()){//d
	  index = nest[i2][j2] -> ID;
	  while(k2 < Ndegree.size()){//c
	    if(index == Ndegree[k2] -> ID){//b
	      if(--(Ndegree[k2] -> indegree) == 0){//a
		q.push(Ndegree[k2]);
		Ndegree.erase(Ndegree.begin() + k2);
		k2 = 0;
		continue;
	      }//a
	    }//b
	    k2++;
	  }//c
	  k2 = 0;
	  j2++;
	}//d
      }//e
      k2 = 0;
      j2 = 1;
      i2++;
    }//f
    i2 = 0;
    j2 = 1;
    k2 = 0;
  }//g
  
}

void topological::traverseV(){
  for(int i = 0; i < Ndegree.size(); i++){
    cout << Ndegree[i] -> ID << ": " << Ndegree[i] -> indegree << endl;
  }
}

void topological::traverseNest(){
  for(int a = 0; a < nest.size(); a++){
    cout << "for list with header " << nest[a][0] -> ID;
    for(int b = 0; b < nest[a].size(); b++){
      cout << "there are elements " << nest[a][b] -> ID << endl;
    }
  }
}


int main(int argc, char** argv){
  topological t;
  // following code snippet taken from fileIO2.cpp from the repository
  // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    while(file.good()){
    // read in two strings
    string s1, s2;
    file >> s1;
    file >> s2;

    if(s1 == "0" && s2 == "0"){
      break;
    }
    
    t.makeNest(s1, s2);
    }
    //terminate input
    file.close();

  t.findIn();
  t.topologicalSort();
  cout << endl;
  return 0;
}
