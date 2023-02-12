#include <iostream>
using namespace std;
//simple program to calculate the value of x^n, where n >= 0.

int xton(int a, int b){

  if ((b >1)&&(b != 1)){
  return xton(a, b-1)*a;
  }
  else if(b == 1){
    return a;
  }
  else if(b < 0){
    return 0;
  }
  else{
    return a;
  }
}

int main(){
  int a1, b1, c1;
  cin >> a1;
  cin >> b1;
  c1 = xton(a1, b1);
  cout << c1 << endl;
  return 0;
}
