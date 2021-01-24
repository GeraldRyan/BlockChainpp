#ifndef SHA256_H
#define SHA256_H
#include <string>

class SHA256 {
   protected:
    typedef unsigned char uint8;
    typedef unsigned int uint32;  /// Unsigned int could have only 16 bits in keeping with std. Usually 32 ("long")
    typedef unsigned long long uint64;
    const static uint32 sha256_k[];  // const puts in data or bss segment as "read-only". Static limits scope to this translation(compilation) unit (cpp file). All class instances share this one variable- even if no instance is instantiated. Perfect for fixed hash key
    const static unsigned int SHA224_256_BLOCK_SIZE = (512 / 8);  // => 64

   public:
    void init();
    void update(const unsigned char* message, unsigned int len);
    void final(unsigned char* digest);  // digest is just output of hash function. Not it is not const. How could it be? So it's not in bss/data but heap.
    static const unsigned int DIGEST_SIZE = (256 / 8);

   protected: // why would there be a protected section? All child classes have access to data and functions
   void transform(const unsigned char *message, unsigned int block_nb); // ?? Not sure block_nb. Have to pay attention to this
   unsigned int m_tot_len;
   unsigned int m_len;
   unsigned char m_block[2*SHA224_256_BLOCK_SIZE]; //
   uint32 m_h[8]; 
};

// so we declared a class

std::string sha256(std::string input); // just a function declaration

// Bitwise operations
#define SHA2_SHFR(x, n) (x >> n)  // shift right n digits
#define SHA2_ROTR(x, n) (( x >> n) | (x << ((sizeof(x) << 3) - n ))) // | = bitwise inclusive OR 
#define SHA2_ROTL(x, n) ((x << n) | (x >> ((sizeof(x) << 3) - n ))) // sizeof(x) <<< 3 is supposed to rep word width in bits per spec. 
#define SHA2_CH(x, y, z) ((x & y) ^ (~x & z )) // bitwise AND (&). ^(BItwise XOR) ~Bitwise NOT (one's complement unary) 
#define SHA2_MAJ(x, y, z) ((x & y ) ^ (x & z) ^ (y & z))
#define SHA256_F1(x) (SHA2_ROTR(x, 2) ^ SHA2_ROTR(x, 13) ^ SHA2_ROTR(x,22))
#define SHA256_F2(x) (SHA2_ROTR(x, 6) ^ SHA2_ROTR(x, 11) ^ SHA2_ROTR(x,25))
#define SHA256_F3(x) (SHA2_ROTR(x, 7) ^ SHA2_ROTR(x, 18) ^ SHA2_SHFR(x,3))
#define SHA256_F4(x) (SHA2_ROTR(x, 17) ^ SHA2_ROTR(x, 19) ^ SHA2_SHFR(x,10))
#define SHA2_UNPACK32(x, str)                 \
{                                             \
    *((str) + 3) = (uint8) ((x)      );       \
    *((str) + 2) = (uint8) ((x) >>  8);       \
    *((str) + 1) = (uint8) ((x) >> 16);       \
    *((str) + 0) = (uint8) ((x) >> 24);       \
}
#define SHA2_PACK32(str, x)                   \
{                                             \
    *(x) =   ((uint32) *((str) + 3)      )    \
           | ((uint32) *((str) + 2) <<  8)    \
           | ((uint32) *((str) + 1) << 16)    \
           | ((uint32) *((str) + 0) << 24);   \
}
#endif