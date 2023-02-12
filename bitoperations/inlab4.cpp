#include <iostream>
#include <stdio.h>
#include <string>
#include <climits>

using namespace std;
void tableDump(string (*arr)[5], string (*arr1)[4]);

int main(){
  int a;
  int a_max = INT_MAX;
  int zeroInt = 0;
  int oneInt = 1;
  
  unsigned int b;
  unsigned int b_max = UINT_MAX;
  unsigned int zeroUInt = 0;
  unsigned int oneUInt = 1;

  float f;
  float f_max = 3.402823*(1e38);
  float f_zero = 0.0;
  float f_one = 1.0;

  double d;
  double d_max = 1.7976931348623157E+308;
  double d_zero = 0.0;
  double d_one = 1.0;

  char c;
  char c_max = ' ';
  char c_zero = '0';
  char c_one = '1';

  bool bo;
  bool bo_max = true;
  bool bo_zero = false;
  bool bo_one  = true;

  int* intp;
  int* intNULL = NULL;

  char* cbasep;
  char* cNULL = NULL;

  double* dbasep;
  double* dNULL = NULL;

  int *ap = &zeroInt;
  unsigned int* up = &zeroUInt;
  float* fp = &f_zero;
  char* cp = &c_zero;
  bool* bp = &bo_zero;
  double* dp = &d_zero;
  
	// Replace the empty strings below with
	// the values you found while experimenting.

        
	string nonPointers[6][5] = {
				    {"int", "4" /*size*/, "32767" /*max value*/, "0x00000000" /*zero as stored in hex*/,"0x00000001" /*one as stored in hex*/},
				    {"unsigned int", "4" /*size*/, "65535" /*max value*/, "0x00000000" /*zero as stored in hex*/, "0x00000001" /*one as stored in hex*/},
				    {"float", "4" /*size*/, "2^128" /*max value*/, "0x00000000" /*zero as stored in hex*/, "0x3f800000" /*one as stored in hex*/},
				    {"double", "8" /*size*/, "2^64" /*max value*/, "0x0000000000000000" /*zero as stored in hex*/, "0x3ff0000000000000" /*one as stored in hex*/},
		{"char", "1" /*size*/, "127" /*max value*/, "0x30" /*zero as stored in hex*/, "0x31" /*one as stored in hex*/},
		{"bool", "1" /*size*/, "1" /*max value*/, "0x00" /*zero as stored in hex*/, "0x01" /*one as stored in hex*/},

	};

	string pointers[3][4] = {
		{"int*", "8" /*size*/, "0x000000007fffffff" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
		{"char*", "8" /*size*/, "0x0000000000000020" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
		{"double*", "8" /*size*/, "0x" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
	};

	tableDump(nonPointers, pointers);
	return 0;
}

void tableDump(string (*arr)[5], string (*arr1)[4]){
	for(int i = 0; i < 6; i++){
		printf("Size of %s: %s\n", arr[i][0].c_str(), arr[i][1].c_str());
		printf("Max value of %s: %s\n", arr[i][0].c_str(), arr[i][2].c_str());
		printf("Zero of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][3].c_str());
		printf("One of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][4].c_str());
	}

	printf("-----------------------------------------------------------------------------\n");

	for(int i = 0; i < 3; i++){
		printf("Size of %s: %s\n", arr1[i][0].c_str(), arr1[i][1].c_str());
		printf("Max value of %s: %s\n", arr1[i][0].c_str(), arr1[i][2].c_str());
		printf("NULL of type %s is stored as: %s\n", arr1[i][0].c_str(), arr1[i][3].c_str());
	}
}
