#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Trie {

public:
  bool isEnd = false;
  Trie *next[26] = {nullptr};

  void insert(string word) {

    int len = word.length();
    Trie *node = this;
    for (int i = 0; i < len; i++) {
      int letter = word[i] - 'a';
      if (node->next[letter] == nullptr) {
        node->next[letter] = new Trie();
      }

      node = node->next[letter];
    }

    node->isEnd = true;
  }
};

class Solution {
public:
  vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  set<string> ans;
  string path = "";
  int cols = 0;
  int rows = 0;

  bool DFS(int x, int y, vector<vector<char>> &board, Trie *node) {
    if (x < 0 || y < 0 || x >= rows || y >= cols) {
      return false;
    }

    int letter = board[x][y] - 'a';
    if (letter < 0 || letter >= 26 || node->next[letter] == nullptr) {
      return false;
    }

    if (node->next[letter]->isEnd) {
      path.push_back(char(letter + 'a'));
      ans.insert(path);
      path.pop_back();
    }

    path.push_back(board[x][y]);
    board[x][y] ^= 128;
    for (auto &dir : directions) {
      DFS(x + dir[0], y + dir[1], board, node->next[letter]);
    }
    board[x][y] ^= 128;
    path.pop_back();
    return true;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    rows = board.size();
    cols = board[0].size();

    auto node = new Trie();
    for (string &word : words)
      node->insert(word);

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        DFS(i, j, board, node);

    return vector<string>(ans.begin(), ans.end());
  }
};

int main() {

  vector<vector<char>> board = {{'o', 'a', 'b', 'n'},
                                {'o', 't', 'a', 'e'},
                                {'a', 'h', 'k', 'r'},
                                {'a', 'f', 'l', 'v'}};

  vector<string> words = {"oa", "oaa"};

  auto sol = new Solution();
  for (auto &word : sol->findWords(board, words)) {
    cout << word << " ";
  }

  return 0;
}
