#include <climits>
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
  bool isValidBST(TreeNode *root) {

    std::function<bool(TreeNode *, long, long)> validate;
    validate = [&](TreeNode *node, long lower, long upper) -> bool {
      if (node == nullptr) {
        return true;
      }

      if (!(lower < node->val && node->val < upper)) {
        return false;
      }

      return validate(node->left, lower, node->val) &&
             validate(node->right, node->val, upper);
    };

    return validate(root, LONG_MIN, LONG_MAX);
  }
};
