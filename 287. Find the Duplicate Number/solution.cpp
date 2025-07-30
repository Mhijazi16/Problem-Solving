#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int len = nums.size();

      for (int i = 0; i < len; i++) 
        nums[nums[i] % len] += len; 
      
      for (int i = 0; i < len; i++){
        nums[i] /= len; 
        if (nums[i] > 1) 
          return i;
        
      }

      return 0;
    }
};
