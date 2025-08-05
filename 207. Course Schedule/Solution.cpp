#include <set>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

      vector<vector<int>> graph(numCourses); 
      vector<int> state(numCourses);

      for (auto& requisit : prerequisites) {
        graph[requisit[1]].push_back(requisit[0]);
      }

      function<bool(int)> DFS;
      DFS = [&](int course) -> bool{
        if (state[course] == 1) return false;
        if (state[course] == 2) return true;


        state[course] = 1;
        for (auto& requisit : graph[course]) {
          if (DFS(requisit) == false) return false;
        }

        state[course] =  2;
        return true;
      };


      for (int i = 0; i < numCourses; i++) {
        if (DFS(i) == false) {
          return false;
        }
      }

      return true;
    }
};
