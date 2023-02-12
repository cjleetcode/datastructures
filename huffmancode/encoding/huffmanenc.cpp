#include "binary_node.h"
#include "heap.h"
#include "huffmanenc.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;
huffmanenc::huffmanenc(){
  head = NULL;
}

huffmanenc::~huffmanenc(){
  delete head;
}


void huffmanenc::makeHuffTree(){
  if(bh.size() <= 1)
    return;
  while(bh.size() > 1){
    binary_node* l = bh.deleteMin();
    binary_node* r = bh.deleteMin();
    binary_node* n = new binary_node();
    n -> left = l;
    n -> right = r;
    n -> ID = l -> ID + r -> ID;
    n -> freq = l -> freq + r -> freq;
    bh.insert(n);
  }
  
}

binary_node* huffmanenc::findMin(){
  return bh.findMin();
}

void huffmanenc::insert(binary_node* b){
  bh.insert(b);
}

string huffmanenc::bitPath(char c, binary_node* point){
  //found the node to be found
  if(point -> left == NULL & point -> right == NULL){
    return "";
  }
  if((point -> left -> ID).find(c) != string::npos){
    return "0" + bitPath(c, point -> left);
  }
  else if((point -> right -> ID).find(c) != string::npos){
    return "1" + bitPath(c, point -> right);
  }
  else{
    return "";
  }
}

int main(int argc, char** argv){
  huffmanenc h;
  vector<char> s1;
  int stor[95];
  string bits[95];
  for(int i = 0; i < 95; i++){
    stor[i] = 0;
    bits[i] = "";
  }
  //bitz = total number of chars encoded
  //unique = unique characters
  float bitz = 0;
  float unique = 0;
  float frequency = 0;
  //bits in original = bitz*8
  //bits in compressed = size of each path * frequency
  //cost = bitlength* probability
  float cost = 0;

  ifstream file(argv[1]);
  char c;
  while(file.get(c)){
    if(int(c) >= 32){
    stor[int(c) - 32]++;
    if(!count(s1.begin(), s1.end(), c) || s1.size() == 0)
    s1.push_back(c);
    }
  }

  while(!s1.empty()){
    int a1 = int(s1.front()) - 32;
    if(stor[a1] != 0){
      binary_node* n = new binary_node();
      n -> ID = s1.front();
      n -> left = NULL;
      n -> right = NULL;
      n -> freq = stor[a1];
      h.insert(n);
    }
    s1.erase(s1.begin());
  }
  
  h.makeHuffTree();
  h.head = h.findMin();

  //encode data
  for(int i = 0; i < 95; i++){
    if(stor[i] != 0){
      bits[i] = h.bitPath(char(i + 32), h.head);
    }
  }
//print postbits
for(int j = 0; j < 95; j++){
  if(bits[j] != ""){
    if(j == 0)
      cout << "space " << bits[j] << endl;
    else{
    cout << char(j + 32) << " " << bits[j] << endl;
    }
    unique++;
  }
 }

cout << "----------------------------------------" << endl;
//print encoded message
ifstream file2(argv[1]);
char c2;
while(file2.get(c2)){
  if(int(c2) >= 32){
  cout << bits[int(c2) - 32] << " ";
  bitz++;
  frequency += bits[int(c2) - 32].length();
  }
 }

 for(int n = 0; n < 96; n++){
   cost += bits[n].length()*stor[n]/bitz;
 }
 cout << endl;
cout << "----------------------------------------" << endl;

cout << "There are a total of " << bitz << " symbols that are encoded." << endl;
 cout << "There are " << unique << " distinct symbols used." << endl;
cout << "There were " << bitz*8 << " bits in the original file." << endl;
cout << "There were " << frequency << " bits in the compressed file." << endl;
float f = bitz*8/frequency;
cout << "This gives a compression ration of " << std::setprecision(6) << f << "." << endl;
cout << "The cost of the Huffman tree is " << std::setprecision(6) << cost << " bits per character.";
  return 0;
}
