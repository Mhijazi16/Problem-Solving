#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {

    sort(nums.begin(), nums.end());
    auto ans = vector<vector<int>>();
    int len = nums.size();

    auto backtrack = function<void(int, vector<int>)>();
    backtrack = [&](int index, vector<int> path) {
      if (index == len) {
        ans.push_back(path);
        return;
      }

      path.push_back(nums[index]);
      backtrack(index + 1, path);
      path.pop_back();
      int current = nums[index];
      while (index < len && current == nums[index]) {
        index++;
      }
      backtrack(index, path);
    };

    backtrack(0, {});
    return ans;
  }
};
