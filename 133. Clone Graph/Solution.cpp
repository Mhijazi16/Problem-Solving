#include <functional>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *node) {

    unordered_map<Node *, Node *> seen;

    function<Node *(Node *)> DFS;
    DFS = [&](Node *root) -> Node * {
      if (root == nullptr) {
        return nullptr;
      }

      if (seen.find(root) != seen.end()) {
        return seen[root];
      }

      auto new_node = new Node(root->val);
      seen[root] = new_node;

      for (auto &neighbor : root->neighbors) {
        new_node->neighbors.push_back(DFS(neighbor));
      }

      return new_node;
    };

    return DFS(node);
  }
};
