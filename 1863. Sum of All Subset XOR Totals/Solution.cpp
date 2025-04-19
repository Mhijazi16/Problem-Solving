#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  int subsetXORSum(vector<int> &nums) {

    int total = 0, len = nums.size();

    function<void(int, int)> DFS;
    DFS = [&](int index, int sum) {
      if (index == len) {
        total += sum;
        return;
      }

      sum ^= nums[index];
      DFS(index + 1, sum);
      sum ^= nums[index];
      DFS(index + 1, sum);
    };

    DFS(0, 0);
    return total;
  }
};
