#include <chrono>
#include <iostream>

#include "sha256/sha256.h"
#define el endl  // try this

using std::cout;
using std::endl;
using std::string;
using namespace std::chrono;

// THIS WILL TEST SHA256 FUNCTION
int main(int argc, char* argv[]) {
    string input = "grape";
    auto start = high_resolution_clock::now();
    string output1 = sha256(input);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "sha256('" << input << "'):" << output1 << endl;
    cout << "Duration: " << duration.count() << endl;
    return 0;
}