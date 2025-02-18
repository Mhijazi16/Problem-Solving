#include <iostream>
#include <vector>

using namespace std;

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
  int maxi = 0;
  int maxDepth(TreeNode* root) {

    if (root == nullptr)
      return 0;

    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;

    return left * (left > right) + right * (left <= right);
  }
};


int main(){

  auto one = new TreeNode(1);
  auto three = new TreeNode(3,one,nullptr);
  auto two = new TreeNode(2,three,nullptr);
  auto root = new TreeNode(0,two, nullptr);

  auto sol = new Solution();
  cout << sol->maxDepth(root);

  return 0;
}
