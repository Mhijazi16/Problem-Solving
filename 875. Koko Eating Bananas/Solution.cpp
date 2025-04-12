#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool works(vector<int> piles, int time, int speed) {
    long long hours = 0;
    for (int &pile : piles) {
      hours += (pile + 1LL * speed - 1) / speed;
    }
    return hours <= time;
  }

  int minEatingSpeed(vector<int> &piles, int h) {
    int min_speed = 1;
    int max_speed = *max_element(piles.begin(), piles.end());
    int ans = max_speed;

    while (min_speed <= max_speed) {
      int mid = min_speed + (max_speed - min_speed) / 2;

      if (works(piles, h, mid)) {
        ans = min(ans, mid);
        max_speed = mid - 1;
      } else {
        min_speed = mid + 1;
      }
    }

    return ans;
  }
};

int main() {

  auto sol = new Solution();
  vector<int> piles = {312884470};
  cout << sol->minEatingSpeed(piles, 312884469);

  return 0;
}
