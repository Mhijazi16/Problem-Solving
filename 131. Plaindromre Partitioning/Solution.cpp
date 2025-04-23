#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPlaindrome(string word) {
    int left = 0, right = word.length() - 1;
    while (left < right) {
      if (word[left] != word[right]) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }

  vector<vector<string>> partition(string s) {

    vector<vector<string>> ans;
    vector<string> path;

    int len = s.length();
    function<void(int)> DFS;
    DFS = [&](int start) {
      if (start >= len) {
        ans.push_back(path);
        return;
      }

      for (int i = 1; i + start < len; i++) {
        string sub = s.substr(start, i);
        if (isPlaindrome(sub)) {
          path.push_back(sub);
          DFS(start + i);
          path.pop_back();
        }
      }
    };

    DFS(0);
    return ans;
  }
};

int main() {

  auto sol = new Solution();
  auto res = sol->partition("aab");
  for (auto &x : res) {
    for (auto &y : x) {
      cout << y << " ";
    }
    cout << endl;
  }

  return 0;
}
