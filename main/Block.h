#include <cstdint>
#include <iostream>

using namespace std;

class Block
{

public:
  string sPrevHash;
  Block(uint32_t nIndexIn, const string &sDataIn); // class constructor. const plus reference means don't copy but still don't change. improve efficiency
  string GetHash();
  void MineBlock(uint32_t nDifficulty);

private:
  uint32_t _nIndex;
  int64_t _nNonce;
  string _sData;
  string _sHash;
  time_t _tTime;
  string _CalculateHash() const; //https://en.cppreference.com/w/cpp/language/member_functions#const-_and_volatile-qualified_member_functions

};