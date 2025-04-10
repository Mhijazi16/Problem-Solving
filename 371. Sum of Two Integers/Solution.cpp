
#include <iostream>
using namespace std;

// 0101
// 0011
// 0000
class Solution {
public:
  int getSum(int a, int b) {
    int ans = 0, i = 0;
    int mask = 1;
    bool carray = false;

    while (i < 32) {
      int bit1 = a & mask ? 1 : 0;
      int bit2 = b & mask ? 1 : 0;

      if (bit1 != bit2) {
        if (!carray) {
          ans |= mask;
        }
      } else if (bit1 == 1 && bit2 == 1) {
        if (carray) {
          ans |= mask;
        }
        carray = true;
      } else if (carray) {
        ans |= mask;
        carray = false;
      }

      i++;
      mask <<= 1;
    }

    return ans;
  }
};

int main() {

  auto sol = new Solution();
  cout << sol->getSum(20, 30);

  return 0;
}
