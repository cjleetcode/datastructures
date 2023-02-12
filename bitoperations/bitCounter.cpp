/*
Caleb Lee
CS 2150
23 September 2021
cjl2pub
bitCounter.cpp
*/

#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int bitCounter(int i){
  if(i == 1)
    return 1;
  else if(i == 0)
    return 0;
  else{
    if(i % 2 == 0)
      return bitCounter(i / 2);
    else{
      return bitCounter(i / 2) + 1;
    }
  }
}
  
void baseConverter(int numBits, string convert, int base1, int base2){
  if(numBits < convert.length()){
    cout << "invalid syntax; convert is longer than the number of expected bits" << endl;
    return;
  }
  
  char conv[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
		 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
		 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  int newArr[numBits];
  double base10 = 0;
  int indexNULL = 0;
  for(int a = 0; a < numBits; a++){
    if(a < convert.length()){
      for(int index = 0; index < 36; index++){
	//converting charcter at index a to numeric value
	if(conv[index] == convert.at(a)){
	  newArr[a] = index;
	  break;
	}
	
      }
    }

    else{
      indexNULL = a;
      break;
    }
  }
  // flipping array
   int newArr2[indexNULL];
   for(int flip = 0; flip < indexNULL; flip++){
     newArr2[flip] = newArr[indexNULL - flip - 1];
   }
  //converting to base 10
  for(int b = 0; b < indexNULL; b++){
    base10 += newArr2[b]*pow(base1, b);
  }

  if(base2 == 10){
  cout << convert << " (base " << base1 << ") = " << base10 << " (base 10)"  << endl;
  return;
  }

  else{
  int count = 0;
  double prevBase = base10;
  //counting remainder size
  for(int c = 0; c < numBits; c++){
    if(floor(base10/base2) == 0)
      break;
    count++;
    base10 = base10 /base2;
  }

  count++;
  base10 = prevBase;
  string newBase = "";
    for(int d = 0; d < count; d++){
      newBase += to_string((int)floor((int)base10 % base2));
      base10 = base10/ (double)base2;
  }
    reverse(newBase.begin(), newBase.end());
  cout << convert << " (base " << base1 << ") = " << newBase << " (base " << base2 << ")" << endl;
  }

}

int main(int argc, char **argv){
  cout << argv[1] << " has " << bitCounter(stoi(argv[1])) << " bit(s)" << endl;

  baseConverter(99, argv[2], stoi(argv[3]), stoi(argv[4]));
}
