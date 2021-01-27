#include <cstdint>
#include <vector>
#include "Block.h" // this doesn't include definitions, just declarations. Definitions are included via Linker at Link Time

using namespace std;

class Blockchain
{
public:
  Blockchain();
  void AddBlock(Block bNew);

private:
  uint32_t _nDifficulty;
  vector<Block> _vChain; // dependency is above
  Block _GetLastBlock() const; // barred from changing. Like a peek method
};