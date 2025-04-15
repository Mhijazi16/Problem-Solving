#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

    vector<vector<int>> ans;
    vector<int> path;
    int len = candidates.size();

    sort(candidates.begin(), candidates.end());

    function<void(int, int)> DFS;
    DFS = [&](int sum, int index) {
      if (sum == target) {
        ans.push_back(path);
        return;
      }

      if (sum > target || index == len) {
        return;
      }

      path.push_back(candidates[index]);
      DFS(sum + candidates[index], index + 1);
      path.pop_back();

      while (index + 1 < len && candidates[index] == candidates[index + 1]) {
        index++;
      }

      DFS(sum, index + 1);
    };

    DFS(0, 0);
    return ans;
  }
};

int main() {
  auto sol = new Solution();
  auto nums = vector<int>{10, 1, 2, 7, 6, 1, 5};
  auto res = sol->combinationSum2(nums, 8);
  for (vector<int> x : res) {
    for (int y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
  return 0;
}
