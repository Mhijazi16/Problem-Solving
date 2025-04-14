#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct Compare {
  bool operator()(const pair<int, int> one, const pair<int, int> two) {
    return one.second < two.second;
  }
};

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    for (int &x : nums)
      freq[x]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;

    for (const auto &pair : freq) {
      heap.push(pair);
    }

    vector<int> res;
    while (k--) {
      res.push_back(heap.top().first);
      heap.pop();
    }

    return res;
  }
};
