#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

      int sum = 0, start = 0, end = 0, ans = INT32_MAX, len = nums.size();

      while (end < len) {
        sum += nums[end];
        while (sum >= target) {
          ans = min(ans, (end - start) + 1);
          sum -= nums[start];
          start++;
        }

        end++;
      }

      return ans == INT32_MAX ? 0 : ans; 
    }
};
