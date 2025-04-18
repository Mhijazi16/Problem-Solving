#include <functional>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

    vector<TreeNode *> ancestors;

    function<void(TreeNode *, TreeNode *, vector<TreeNode *> &)> DFS;
    DFS = [&](TreeNode *node, TreeNode *target, vector<TreeNode *> &path) {
      if (node == nullptr) {
        return;
      }

      path.push_back(node);

      if (target->val < node->val)
        DFS(node->left, target, path);
      else if (target->val > node->val)
        DFS(node->right, target, path);
    };

    vector<TreeNode *> first;
    DFS(root, p, first);
    vector<TreeNode *> second;
    DFS(root, q, second);

    int i = 0;
    while (i < first.size() && i < second.size() && first[i] == second[i]) {
      i++;
    }

    return first[i - 1];
  }
};
