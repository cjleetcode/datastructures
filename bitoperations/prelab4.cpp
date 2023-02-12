#include <array>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

void sizeOfTest(){
  int a; unsigned int b; float c; double d; char e; bool f; int* g; char* h; double* i;
  cout << "Size of int: " << sizeof(a) << endl;
  cout << "Size of unsigned int: " << sizeof(b) << endl;
  cout << "Size of float: " << sizeof(c) << endl;
  cout << "Size of double: " << sizeof(d) << endl;
  cout << "Size of char: " << sizeof(e) << endl;
  cout << "Size of bool: " << sizeof(f) << endl;
  cout << "Size of int*: " << sizeof(g) << endl;
  cout << "Size of char*: " << sizeof(h) << endl;
  cout << "Size of double*: " << sizeof(i) << endl;
}

void overflow(){
  unsigned int aa = UINT_MAX;
  unsigned int ab = aa + 1;
  cout << aa << " + 1 =  " << ab << endl;
}

void outputBinary(int i){
  int arr[32];
  int stor = i;
  for(int pre = 0; pre < 32; pre++){
    arr[pre] = 0;
  }
  
  for(int a = 0; a < 32; a++){
    arr[31 - a] = stor % 2;
    stor /= 2;
  }

  for(int b = 0; b < 32; b++){
    cout << arr[b];
    if((b + 1) % 4 == 0){
      cout << " ";
    }
  }
  cout << endl;
}



int main(){
  int i;
  cin >> i;
  sizeOfTest();
  overflow();
  outputBinary(i);
  return 0;
}
