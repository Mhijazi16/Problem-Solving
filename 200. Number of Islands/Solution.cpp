#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {

    int rows = grid.size(), cols = grid[0].size(), count = 0;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    function<void(int, int)> DFS;
    DFS = [&](int x, int y) {
      if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == '0') {
        return;
      }

      grid[x][y] = '0';

      for (auto &dir : directions) {
        DFS(x + dir[0], y + dir[1]);
      }
    };

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        if (grid[i][j] == '1') {
          count++;
          DFS(i, j);
        }

    return count;
  }
};
