#include "MurmurHash3.h"
#include "BloomFilter.h"
#include <array>

//Bloom filter constructor
BloomFilter::BloomFilter(uint64_t size, uint8_t numHashes)
      : m_bits(size), m_numHashes(numHashes) {}


//Hash array created using the MurmurHash3 code
std::array<uint64_t, 2> hash(const uint8_t *data, std::size_t len)
{
  std::array<uint64_t, 2> hashValue;
  MurmurHash3_x64_128(data, len, 0, hashValue.data());
  return hashValue;
}


//Hash array created using the MurmurHash3 code
inline size_t nthHash(int n, uint64_t hashA, uint64_t hashB, size_t filterSize)
{
    return (hashA + n * hashB) % filterSize;
}


//Adds an element to the array
void BloomFilter::add(const uint8_t *data, std::size_t len) {
    auto hashValues = hash(data, len);
    for (int n = 0; n < m_numHashes; n++)
    {
        m_bits[nthHash(n, hashValues[0], hashValues[1], m_bits.size())] = true;
    }
}


//Returns true or false based on a probabilistic assesment of the array
bool BloomFilter::find(const uint8_t *data, std::size_t len) 
{
    auto hashValues = hash(data, len);
    for (int n = 0; n < m_numHashes; n++)
    {
        if (!m_bits[nthHash(n, hashValues[0], hashValues[1], m_bits.size())])
        {
            return false;
        }
    }
    return true;
}
