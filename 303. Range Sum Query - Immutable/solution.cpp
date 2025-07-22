#include <vector>


using namespace std;

class NumArray {
public:
  vector<int> prefix;

    NumArray(vector<int>& nums) {
      prefix.push_back(0);
      int len = nums.size(), total = 0;

      for (int i = 0; i < len; i++) {
        total += nums[i];
        prefix.push_back(total);
      }
    }
    
    int sumRange(int left, int right) {
      return prefix[right+1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
