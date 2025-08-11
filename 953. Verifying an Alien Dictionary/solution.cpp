#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:

    bool isAlienSorted(vector<string>& words, string order) {
      unordered_map<char, int> alphabet; 
      int len = order.size();

      for (int i = 0; i < len; i++) {
        alphabet[order[i]] = i;
      }

      len = words.size();
      for (int i = 0; i < len-1; i++) {
        string& first = words[i];
        string& second = words[i+1];

        int idx = 0; 
        bool flag = false;
        while (idx < first.length() && idx < second.length()) {
          if (alphabet[first[idx]] < alphabet[second[idx]]) {
            flag = true;
            break;
          }
          else if (alphabet[first[idx]] > alphabet[second[idx]]) {
            return false;
          }

          idx++;
        }

        if (!flag && first.length() < second.length()) {
          return false;
        }
      }

      return true;
    }
};
