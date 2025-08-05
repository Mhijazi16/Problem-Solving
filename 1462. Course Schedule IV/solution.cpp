#include <functional>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

      vector<vector<bool>> reachable(numCourses, vector(numCourses, false)); 

      for (auto& requisit : prerequisites) {
        reachable[requisit[1]][requisit[0]] = true;
      }

      for (int k = 0; k < numCourses; k++)
        for (int i = 0; i < numCourses; i++)
          for (int j = 0; j < numCourses; j++)
            if (reachable[i][k] && reachable[k][j]) {
              reachable[i][j] = true;
            }

      vector<bool> ans;
      for (auto& query : queries) {
        ans.push_back(reachable[query[1]][query[0]]);
      }

      return ans;
    }
};
