#include <functional>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &grid) {

    map<pair<int, int>, bool> seen;
    vector<pair<int, int>> tmp;
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int rows = grid.size(), cols = grid[0].size();

    function<void(int, int, int)> DFS;
    DFS = [&](int x, int y, int prev) {
      if (x < 0 || y < 0 || x == rows || y == cols || seen[{x, y}] ||
          grid[x][y] < prev) {
        return;
      }

      seen[{x, y}] = true;
      tmp.push_back({x, y});

      for (auto &dir : direction) {
        DFS(x + dir[0], y + dir[1], grid[x][y]);
      }
    };

    for (int i = 0; i < cols; i++) {
      DFS(0, i, grid[0][i]);
    }
    for (int i = 0; i < rows; i++) {
      DFS(i, 0, grid[i][0]);
    }
    vector<pair<int, int>> pacific = tmp;
    tmp.clear();
    seen.clear();
    for (int i = 0; i < cols; i++) {
      DFS(rows - 1, i, grid[rows - 1][i]);
    }
    for (int i = 0; i < rows; i++) {
      DFS(i, cols - 1, grid[i][cols - 1]);
    }

    vector<vector<int>> ans;

    map<pair<int, int>, bool> count;
    for (auto &x : tmp) {
      count[{x.first, x.second}] = true;
    }
    for (auto &x : pacific) {
      if (count[{x.first, x.second}]) {
        ans.push_back({x.first, x.second});
      }
    }

    return ans;
  }
};
