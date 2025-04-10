#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int count_ones(int n) {
    int count = 0;
    while (n) {
      n = n & (n - 1);
      count++;
    }

    return count;
  };
  vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < ans.size(); i++) {
      ans[i] = count_ones(i);
    }

    return ans;
  }
};
