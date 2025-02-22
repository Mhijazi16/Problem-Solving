#include <algorithm>
#include <cstdlib>
#include <functional>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {

      bool balanced = true;
      std::function<int(TreeNode*)> DFS;
      DFS = [&](TreeNode* root){

        if (!root) {
          return 0;
        }

        int left = DFS(root->left);
        int right = DFS(root->right);

        if (abs(left-right) > 1) {
          balanced = false;
        }

        return std::max(left, right) + 1;
      };

      DFS(root);
      return balanced;
    }
};
