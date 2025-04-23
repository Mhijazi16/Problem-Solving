#include <functional>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {

    if (digits == "") {
      return {};
    }

    vector<string> ans;
    string path;
    int len = digits.size();

    vector<vector<char>> map = {
        {' '},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'},
    };

    function<void(int)> DFS;
    DFS = [&](int index) {
      if (index == len) {
        ans.push_back(path);
        return;
      }

      for (char &x : map[digits[index] - '0']) {
        path.push_back(x);
        DFS(index + 1);
        path.pop_back();
      }
    };

    DFS(0);
    return ans;
  }
};
