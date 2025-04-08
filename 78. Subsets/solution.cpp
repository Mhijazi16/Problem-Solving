#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {

    auto ans = vector<vector<int>>();
    auto tmp = vector<int>();

    auto backtrack = function<void(int)>();
    backtrack = [&](int index) {
      if (nums.size() <= index) {
        ans.push_back(tmp);
        return;
      }

      backtrack(index + 1);
      tmp.push_back(nums[index]);
      backtrack(index + 1);
      tmp.pop_back();
    };

    backtrack(0);
    return ans;
  }
};
