#include <functional>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {

    vector<vector<int>> ans;
    map<pair<int, int>, bool> seen;

    function<void(int, vector<int>)> DFS;
    DFS = [&](int current, vector<int> path) {
      if (current > n + 1) {
        return;
      }
      if (path.size() == k) {
        ans.push_back(path);
        return;
      }

      path.push_back(current);
      DFS(current + 1, path);
      path.pop_back();
      DFS(current + 1, path);
    };

    DFS(1, {});
    return ans;
  }
};
