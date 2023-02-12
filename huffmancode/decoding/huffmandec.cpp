// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.
#include "huffmandec.h"
#include "binary_node.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

huffmandec::huffmandec(){
  head = new binary_node();
  head -> ID = 'a';
  head -> left= NULL;
  head -> right = NULL;
}

void huffmandec::makeHuffNode(binary_node* n, char c, string dir){
  binary_node* n1 = new binary_node();
    n1 -> ID = c;
    n1 -> left = NULL;
    n1 -> right = NULL;

  if(dir.length() == 0){
    return;
  }
  if(n == NULL) {
    cout << n1->left << endl;
    cout << n1->right << endl;
    n = n1;
  }
  
  if(dir[0] == '1'){
      dir.erase(dir.begin());
      if(n -> right ==NULL)
      n -> right = n1;
      makeHuffNode(n -> right, c, dir);
  }
  else if(dir[0] == '0'){
      dir.erase(dir.begin());
      if(n -> left == NULL)
      n -> left = n1;
      makeHuffNode(n -> left, c, dir);
  }

  else{
    cout << "lol" << endl;
  }
}

void huffmandec::decode(binary_node* n, string bits){
  //checks if either at index = 1 or there are children of the node, and if the string hasn't ended AND if there is something in the current node
  if( n == NULL){
    return;
  }
  if(bits.length() <= 0){
    cout << n -> ID;
    return;
  }
  if(n -> left == NULL && n -> right == NULL){
    cout << n -> ID;
    decode(head, bits);
  }

  if(bits[0] == '0'){
    bits.erase(bits.begin());
    decode(n -> left, bits);
  }
  else if(bits[0] == '1'){
    bits.erase(bits.begin());
    decode(n -> right, bits);
  }
  else{
    cout << "u bad lul" << endl;
  }
}

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    huffmandec h;
    h.head = new binary_node();
    h.head -> left = NULL;
    h.head -> right = NULL;
    while (true) {
      string character;
      string prefix;
      char c1;

        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space"){
	  c1 = char(32);
        }
	else{
	  c1 = character[0];
	}
        // read in the prefix code
        file >> prefix;
	
	h.makeHuffNode(h.head, c1, prefix);
        // do something with the prefix code
	// cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    //read in last part of the file: the encoded data
   
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    h.decode(h.head, allbits);
    // close the file before exiting
    cout << endl;
    file.close();

    return 0;
}
