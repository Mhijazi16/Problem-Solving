#include <algorithm>
#include <functional>

using namespace std;

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
  int diameterOfBinaryTree(TreeNode *root) {

    int diameter = 0;
    std::function<int(TreeNode(*))> DFS;
    DFS = [&](TreeNode *node) -> int {
      if (node == nullptr) {
        return 0;
      }

      int left = DFS(node->left) + 1;
      int right = DFS(node->right) + 1;

      diameter = max(diameter, left + right);
      return max(left, right);
    };

    DFS(root);
    return diameter;
  }
};
