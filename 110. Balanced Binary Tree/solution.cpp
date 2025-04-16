#include <algorithm>
#include <cstdlib>
#include <functional>
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
  bool isBalanced(TreeNode *root) {

    bool isbalanced = true;
    std::function<int(TreeNode *)> DFS;
    DFS = [&](TreeNode *node) -> int {
      if (node == nullptr) {
        return 0;
      }

      int left = DFS(node->left);
      int right = DFS(node->right);

      if (abs(left - right) > 1) {
        isbalanced = false;
      }

      return std::max(left, right) + 1;
    };

    DFS(root);
    return isbalanced;
  }
};
