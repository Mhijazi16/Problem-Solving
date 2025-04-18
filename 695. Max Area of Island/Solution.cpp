#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {

    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int rows = grid.size(), cols = grid[0].size();
    int sum = 0, ans = 0;

    function<void(int, int)> DFS;
    DFS = [&](int x, int y) {
      if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0) {
        return;
      }

      grid[x][y] = 0;
      sum++;

      for (auto &dir : directions) {
        DFS(x + dir[0], y + dir[1]);
      }
    };

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        if (grid[i][j] == 1) {
          sum = 0;
          DFS(i, j);
          ans = max(ans, sum);
        }

    return ans;
  }
};
