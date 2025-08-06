#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

      vector<int> ans;
      int len = nums.size(), middle = 0;
      while (middle < len && nums[middle] < 0) {
        middle++;
      }

      int one = middle - 1; 
      int two = middle;
      while (one >= 0 && two < len) {
        int first = nums[one] * nums[one];
        int second = nums[two] * nums[two];

        if (first < second) {
          ans.push_back(first);
          one--;
        }
        else{
          ans.push_back(second);
          two++;
        }
      }

      while (two < len) {
        ans.push_back(nums[two]* nums[two++]);
      }

      while (one >= 0 ) {
        ans.push_back(nums[one] * nums[one--]);
      }

      return ans;
    }
};
