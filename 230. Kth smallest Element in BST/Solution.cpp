
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
  int kthSmallest(TreeNode *root, int k) {

    int ans = root->val;
    std::function<void(TreeNode *)> DFS;
    DFS = [&](TreeNode *node) {
      if (node == nullptr) {
        return;
      }

      DFS(node->left);
      if (--k == 0)
        ans = node->val;
      DFS(node->right);
    };

    DFS(root);
    return ans;
  }
};
