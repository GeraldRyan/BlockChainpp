#include "Block.h"
#include "sha256/sha256.h"
#include <sstream>

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);  // what is this?

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);
    cout << "Block Mined" << _sHash << endl;
}

inline string Block::_CalculateHash() const{ // inline triggers compiler optimization. Fewer separate calls. 

std::stringstream ss; // 4 basic mehods, clear(), str()
ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash; // << = add >> = read;
// cout << ss.str(); // Just see what this does.  
return sha256(ss.str());
}