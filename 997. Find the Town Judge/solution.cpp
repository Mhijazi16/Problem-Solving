#include <unordered_map>
#include <vector>

using namespace  std; 

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      vector<int> inDegree(n+1, 0);
      vector<int> outDegree(n+1, 0);

      for (auto& edge : trust) {
        inDegree[edge[1]]++;
        outDegree[edge[0]]++;
      }

      for (int i = 1; i <= n; i++) {
        if (outDegree[i] == 0 && inDegree[i] == n-1) {
          return i;
        }
      }

      return -1;
    }
};
