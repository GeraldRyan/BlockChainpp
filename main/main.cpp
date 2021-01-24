#include <iostream>
#include "sha256/sha256.h"
#define el endl // try this

using std::string;
using std::cout;
using std::endl;

// THIS WILL TEST SHA256 FUNCTION
int main(int argc, char* argv[]){
  string input = "grape";
  string output1 = sha256(input);

  cout << "sha256('"<< input << "'):" << output1 << endl;
  return 0;
}