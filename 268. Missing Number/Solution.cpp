#include <vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {

    int ans = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      ans ^= nums[i] ^ i;
    }
    return ans;
  }
};
