#include <functional>
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
  vector<int> rightSideView(TreeNode *root) {
    int depth = 0;
    vector<int> ans;

    function<void(TreeNode *, int)> DFS;
    DFS = [&](TreeNode *node, int current) {
      if (node == nullptr)
        return;

      if (current >= depth) {
        ans.push_back(node->val);
        depth++;
      }

      DFS(node->right, current + 1);
      DFS(node->left, current + 1);
    };

    DFS(root, 0);
    return ans;
  }
};
