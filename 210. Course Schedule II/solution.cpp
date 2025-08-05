#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

      vector<vector<int>> graph(numCourses);
      vector<int> inDegrees(numCourses);
      vector<int> ans;
      queue<int> queue;


      for (auto& requisit : prerequisites) {
        graph[requisit[1]].push_back(requisit[0]);
        inDegrees[requisit[0]]++;
      }

      for (int i = 0; i < numCourses; i++) {
        if (inDegrees[i] == 0) 
          queue.push(i);
      }

      while (!queue.empty()) {
        int course = queue.front(); 
        queue.pop();

        ans.push_back(course);
        for (auto& neighbour : graph[course]) {
          if (--inDegrees[neighbour] == 0) 
            queue.push(neighbour);
        }
      }


      return ans.size() == numCourses? ans : vector<int>();
    }
};
