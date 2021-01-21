#ifndef SHA256_H
#define SHA256_H
#include <string>

class SHA256 {
   protected:
    typedef unsigned char uint8;
    typedef unsigned int uint32;  /// Unsigned int could have only 16 bits in keeping with std. Usually 32 ("long")
    typedef unsigned long long uint64;

    const static uint32 sha256_k[];  // const puts in data or bss segment as "read-only". Static limits scope to this translation(compilation) unit (cpp file). All class instances share this one variable- even if no instance is instantiated. Perfect for fixed hash key

    const static unsigned int SHA224_256_BLOCK_SIZE = (512 / 8); // => 64

   public:
    void init();
    void update(const unsigned char* message, unsigned int len);
    

};