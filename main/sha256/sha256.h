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
   unsigned int m_total_len;
   unsigned int m_len;
   unsigned char m_block[2*SHA224_256_BLOCK_SIZE]; //
   uint32 m_h[8]; 
};

// so we declared a class

std::string sha256(std::string input); // just a function declaration

#define SHA2SHFR(x, n) (x >> n)  // shift right n digits
#define SHA2_ROTR(x, n) (( x >> n) | (x << ((sizeof(x) << 3) - n ))) // | = bitwise inclusive OR 
#define SHA2_ROTL(x, n) ((x << n) | (x >> ((sizeof(x) << 3) - n ))) // maybe can test and debug and console this. Dump or something. 
#define SHA2_CH(x, y, z) ((x & t) ^ (~x & z )) // bitwise AND (&). ^(BItwise XOR) ~Bitwise NOT (one's complement unary) 
#define 
#define 
#define 
#define 


#endif