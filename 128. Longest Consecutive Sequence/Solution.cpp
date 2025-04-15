#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  // 1 2 3 4 100 200
  int longestConsecutive(vector<int> &nums) {
    set<int> st;
    for (const int &x : nums) {
      st.insert(x);
    }

    int tmp = 1, ans = 0;
    auto one = st.begin();
    for (auto two = next(st.begin()); two != st.end(); two++) {
      if (*one + 1 == *two)
        tmp++;
      else
        tmp = 0;

      ans = max(ans, tmp);
      one = next(one);
    }

    return ans;
  }
};

int main() {

  auto sol = new Solution();
  vector<int> nums = {100, 4, 200, 3, 2, 1};
  cout << sol->longestConsecutive(nums);

  return 0;
}
