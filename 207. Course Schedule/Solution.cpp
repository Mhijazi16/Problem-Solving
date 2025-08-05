#include <queue>
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
      vector<int> inDegrees(numCourses);
      queue<int> queue;

      for (auto& requisit : prerequisites) {
        graph[requisit[1]].push_back(requisit[0]);
        inDegrees[requisit[0]]++;
      }

      for (int i = 0; i < numCourses; i++) 
        if (inDegrees[i] == 0) queue.push(i); 


      int courses = 0;
      while (!queue.empty()) {
        int current = queue.front(); queue.pop();
        courses++;
        for (auto& neighbour : graph[current]) 
          if (--inDegrees[neighbour] == 0) 
            queue.push(neighbour);
      }

      return  courses == numCourses;
    }
};
