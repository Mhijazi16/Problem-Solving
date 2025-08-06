#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

      int sum = 0; 
      for (int& x : nums) 
        sum += x;

      int len = nums.size(), left = 0, right = sum;
      for (int i = 0; i < len; i++) {
        right -= nums[i];
        if (left == right) {
          return i; 
        }

        left += nums[i];
      }

      return -1;
    }
};
