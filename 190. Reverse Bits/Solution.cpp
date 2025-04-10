#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {

    uint32_t mask1 = 1u << 31;
    uint32_t mask2 = 1;

    while (mask1 > mask2) {
      uint32_t x1 = n & mask1 ? 1 : 0;
      uint32_t x2 = n & mask2 ? 1 : 0;

      if (x1 != x2) {
        n ^= mask1;
        n ^= mask2;
      }

      mask1 >>= 1;
      mask2 <<= 1;
    }

    return n;
  }
};

int main() {

  uint32_t n = 4294967293;
  auto sol = new Solution();
  cout << sol->reverseBits(n) << endl;
}
