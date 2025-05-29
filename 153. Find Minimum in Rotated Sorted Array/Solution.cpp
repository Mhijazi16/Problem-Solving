#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return nums[left];
  }
};

int main() {

  auto sol = new Solution();
  vector<int> nums = {3, 4, 0, 1, 2};
  cout << sol->findMin(nums);
}
