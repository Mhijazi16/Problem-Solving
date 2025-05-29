
#include <algorithm>
#include <cstdint>
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
  int maxPathSum(TreeNode *root) {

    int ans = INT32_MIN;
    std::function<void(TreeNode *, int)> DFS;
    DFS = [&](TreeNode *node, int sum) {
      if (node == nullptr) {
        return;
      }

      ans = std::max(ans, sum);

      DFS(node->left, sum + node->val);
      DFS(node->right, sum + node->val);

      DFS(node->left, sum);
      DFS(node->right, sum);
    };

    DFS(root, 0);
    return ans;
  }
};
