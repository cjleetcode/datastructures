//mathfun.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int main(){
  long n1, n2, prod, pow;

    //prompt user for two integers
  cout << "Enter integer 1: ";
  cin >> n1;
  cout << "" << endl;
  cout << "Enter integer 2: ";
  cin >> n2;
  cout << "" << endl;

  //print results
  prod = product(n1, n2);
  pow = power(n1, n2);
  cout << "Product: " << prod << endl;
  cout << "Power: " << pow << endl;

  //done.
  return 0;
}
