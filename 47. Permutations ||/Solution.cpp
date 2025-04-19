#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {

    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<vector<int>> ans;

    function<void(vector<int> choices, vector<int> path)> backtrack;
    backtrack = [&](vector<int> choices, vector<int> path) {
      int n = choices.size();
      if (n == 0 || path.size() == len) {
        ans.push_back(path);
        return;
      }

      for (int i = 0; i < n; i++) {
        if (choices[i] == -11 || i + 1 < n && choices[i] == choices[i + 1]) {
          continue;
        }

        path.push_back(choices[i]);
        int tmp = choices[i];
        choices[i] = -11;
        backtrack(choices, path);
        path.pop_back();
        choices[i] = tmp;
      }
    };

    backtrack(nums, {});
    return ans;
  }
};
