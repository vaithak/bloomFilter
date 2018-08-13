#ifndef _BLOOMFILTER_H_
#define _BLOOMFILTER_H_
#endif

#include <vector>

class BloomFilter
{
 public:
  BloomFilter(uint64_t size, uint8_t numHashes);
  void add(const uint8_t *data, std::size_t len);
  bool find(const uint8_t *data, std::size_t len);

private:
  uint8_t m_numHashes;
  std::vector<bool> m_bits;
};