#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    unordered_map<int, int> map;
    int left = 0, right = 0, len = fruits.size();
    int length = 0;

    for (int right = 0; right < len; right++) {
      map[fruits[right]]++;
      while (map.size() > 2) {
        map[fruits[left]]--;
        if (map[fruits[left]] == 0) {
          map.erase(fruits[left]);
        }
        left++;
      }

      length = max(length, right - left + 1);
    }

    return length;
  }
};
