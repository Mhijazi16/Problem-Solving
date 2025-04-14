#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> anagrams;

    for (auto &str : strs) {
      string code = "00000000000000000000000000";
      for (auto &c : str)
        code[c - 'a'] = (int(code[c - 'a']) + 1) + '0';
      anagrams[code].push_back(str);
    }

    vector<vector<string>> res;
    for (auto &pair : anagrams) {
      res.push_back(pair.second);
    }

    return res;
  }
};
