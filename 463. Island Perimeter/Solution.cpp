#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {

    int total = 0, rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    function<void(int, int)> DFS;
    DFS = [&](int x, int y) {
      if (x < 0 || y < 0 || x == rows || y == cols || grid[x][y] == 0) {
        total++;
        return;
      }

      if (grid[x][y] == -1) {
        return;
      }

      grid[x][y] = -1;

      for (auto &point : directions) {
        DFS(x + point[0], y + point[1]);
      }
    };

    for (int i = 0; i < rows; i++)
      for (int j = 0; i < cols; j++)
        if (grid[i][j] == 1) {
          DFS(i, j);
          return total;
        }

    return total;
  }
};
