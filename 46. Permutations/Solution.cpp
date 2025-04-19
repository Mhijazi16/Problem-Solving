#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {

    int len = nums.size();
    vector<vector<int>> ans;

    function<void(vector<int>, vector<int>)> DFS;
    DFS = [&](vector<int> path, vector<int> choices) {
      if (choices.size() == 0) {
        return;
      }

      if (path.size() == len) {
        ans.push_back(path);
      }

      for (int i = 0; i < choices.size(); i++) {
        int tmp = choices[i];
        if (tmp == -11) {
          continue;
        }

        path.push_back(tmp);
        choices[i] = -11;
        DFS(path, choices);
        path.pop_back();
        DFS(path, choices);
        choices[i] = tmp;
      }
    };

    DFS({}, nums);
    return ans;
  }
};
