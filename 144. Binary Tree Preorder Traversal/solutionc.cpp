#include <functional>
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
    vector<int> preorderTraversal(TreeNode* root) {

      vector<int> ans; 
      function<void(TreeNode*)> DFS; 
      DFS = [&](TreeNode* node){
        if (node == nullptr) {
          return;
        }

        ans.push_back(node->val);
        DFS(node->left);
        DFS(node->right);
      };

      DFS(root);
      return ans;
    }
};
