#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int, int> map;
      vector<int> ans; 

      for (auto& x : nums1) {
        map[x]++;
      }

      for (auto& x : nums2) {
        if (map[x]) {
          map[x]--;
          ans.push_back(x);
        }
      }

      return ans;
    }
};
