#include <algorithm>
#include <functional>
#include <iostream>

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
    std::function<int(TreeNode*)> DFS; 
    DFS = [&](TreeNode* root) -> int{

      if (!root) {
        return 0;
      }

      int left = DFS(root->left);
      int right = DFS(root->right);

      diameter = std::max(diameter, left+right);
      return std::max(left,right) + 1;
    };

    DFS(root);
    return diameter;
  }
};

int main(){
  return 0;
}
