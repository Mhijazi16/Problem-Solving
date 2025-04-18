#include <functional>
#include <map>
#include <set>
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
  vector<vector<int>> verticalTraversal(TreeNode *root) {

    map<int, map<int, multiset<int>>> mp;

    function<void(TreeNode *, int, int)> DFS;
    DFS = [&](TreeNode *node, int col, int row) {
      if (node == nullptr) {
        return;
      }

      mp[col][row].insert(node->val);

      DFS(node->right, col + 1, row + 1);
      DFS(node->left, col - 1, row + 1);
    };

    DFS(root, 0, 0);

    vector<vector<int>> ans;
    for (auto &rows : mp) {
      vector<int> tmp;
      for (auto &pair : rows.second) {
        for (auto &x : pair.second) {
          tmp.push_back(x);
        }
      }
      ans.push_back(tmp);
    }

    return ans;
  }
};
