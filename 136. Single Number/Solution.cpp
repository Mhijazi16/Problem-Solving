#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int res = 0;
    for (auto &x : nums) {
      res = x ^ res;
    }

    return res;
  }
};
