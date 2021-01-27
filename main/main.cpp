#include <chrono>
#include <iostream>
#include "Blockchain.h"
#include "sha256/sha256.h"
#define el endl  // try this

using std::cout;
using std::endl;
using std::string;
using namespace std::chrono;

// THIS WILL TEST SHA256 FUNCTION
int main(int argc, char* argv[]) {
    Blockchain bChain = Blockchain();
    
    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, "Block 1 Data"));

    cout << "Mining block 2..." << endl; 
    bChain.AddBlock(Block(2, "Block 2 Data"));

    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Block 3 Data"));
    
    return 0;

    // string input = "grape";
    // auto start = high_resolution_clock::now();
    // string output1 = sha256(input);
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);

    // cout << "sha256('" << input << "'):" << output1 << endl;
    // cout << "Duration: " << duration.count() << " (milliseconds)" << el;
    // return 0;
}