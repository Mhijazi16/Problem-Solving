
#include <cstdint>
#include <functional>
#include <ios>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int goodNodes(TreeNode *root) {
    int count = 0, tmp = 0;

    std::function<void(TreeNode *, int)> DFS;
    DFS = [&](TreeNode *node, int maxi) {
      if (node == nullptr) {
        return;
      }

      if (node->val > maxi) {
        count++;
        maxi = node->val;
      }

      DFS(node->left, maxi);
      DFS(node->right, maxi);
    };

    DFS(root, INT32_MIN);
    return count;
  }
};
