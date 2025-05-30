#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

    if (numCourses == 1 || prerequisites.empty()) {
      return true;
    }

    map<int, vector<int>> graph;
    for (auto &tuple : prerequisites) {
      if (tuple[0] == tuple[1]) {
        return false;
      }
      graph[tuple[0]].push_back(tuple[1]);
    }

    unordered_map<int, bool> seen;

    function<bool(int)> DFS;
    DFS = [&](int course) -> bool {
      if (graph[course].empty()) {
        return true;
      }

      if (seen[course]) {
        return false;
      }
      seen[course] = true;

      for (auto &preq : graph[course]) {
        if (!DFS(preq))
          return false;
      }

      return true;
    };

    for (auto &preq : prerequisites) {
      if (!DFS(preq[0]))
        return false;
      ;
    }

    return true;
  }
};
