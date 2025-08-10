#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {

    queue<vector<int>> queue;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int rows = grid.size(), cols = grid[0].size();
    int minutes = 0;

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        if (grid[i][j] == 2)
          queue.push({i, j});

    while (!queue.empty()) {

      vector<vector<int>> oranges;
      while (!queue.empty()) {
        oranges.push_back(queue.front());
        queue.pop();
      }

      bool infected = false;
      for (auto &orange : oranges) {

        for (auto &dir : directions) {
          int x = dir[0] + orange[0];
          int y = dir[1] + orange[1];

          if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == 0 ||
              grid[x][y] == 2) {
            continue;
          }

          queue.push({x, y});
          grid[x][y] = 2;
          infected = true;
        }
      }

      minutes += int(infected);
    }

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        if (grid[i][j] == 1)
          return -1;

    return minutes;
  }
};
