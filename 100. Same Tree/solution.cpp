#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {}
};

class Solution{
  public: 
    bool isSameTree(TreeNode* one, TreeNode* two){
      return false;
    }
};

int main() {

  return 0; 
}
