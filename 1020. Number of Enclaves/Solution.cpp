#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int numEnclaves(vector<vector<int>> &grid) {

    int rows = grid.size(), cols = grid[0].size(), ans = 0, res = 0;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    function<bool(int, int)> DFS;
    DFS = [&](int x, int y) -> bool {
      if (x == 0 || y == 0 || x == rows - 1 || y == cols - 1) {
        if (grid[x][y] == 1) {
          return false;
        }
      }

      if (grid[x][y] == 0) {
        return true;
      }

      ans++;
      grid[x][y] = 0;

      bool success = true;
      for (auto &dir : directions) {
        if (!DFS(x + dir[0], y + dir[1])) {
          grid[x][y] = 0;
          success = false;
        }
      }

      return success;
    };

    for (int i = 1; i < rows - 1; i++)
      for (int j = 1; j < cols - 1; j++) {
        ans = 0;
        if (grid[i][j] == 1 && DFS(i, j)) {
          res += ans;
        }
      }

    return res;
  }
};
