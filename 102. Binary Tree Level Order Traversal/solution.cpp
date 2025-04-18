#include <queue>
#include <vector>

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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      vector<int> tmp;
      int size = q.size();

      while (size--) {
        auto node = q.front();
        tmp.push_back(node->val);

        if (node->left)
          q.push(node->left);

        if (node->right)
          q.push(node->right);

        q.pop();
      }

      res.push_back(tmp);
    }

    return res;
  }
};
