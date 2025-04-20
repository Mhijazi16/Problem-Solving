#include <functional>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {

    vector<vector<int>> ans;

    function<void(int, vector<int>)> DFS;
    DFS = [&](int node, vector<int> path) {
      if (node == graph.size() - 1) {
        path.push_back(node);

        ans.push_back(path);
      }

      path.push_back(node);

      for (auto &edge : graph[node]) {
        DFS(edge, path);
      }
    };

    DFS(0, {});
    return ans;
  }
};
