#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {

    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int len = word.length();
    int cols = board.size();
    int rows = board[0].size();

    function<bool(int, int, int)> DFS;
    DFS = [&](int x, int y, int i) -> bool {
      if (i == len) {
        return true;
      }

      if (x < 0 || y < 0 || x >= cols || y >= rows || word[i] != board[x][y]) {
        return false;
      }

      board[x][y] ^= 128;

      for (auto point : directions) {
        if (DFS(x + point[0], y + point[1], i + 1)) {
          board[x][y] ^= 128;
          return true;
        }
        board[x][y] ^= 128;
      }

      return false;
    };

    for (int i = 0; i < cols; i++)
      for (int j = 0; j < rows; j++)
        if (DFS(i, j, 0))
          return true;

    return false;
  }
};

int main() {
  auto board = vector<vector<char>>{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  auto sol = new Solution();
  cout << sol->exist(board, "ABCB") << endl;

  return 0;
}
