
struct TreeNode{
  int val; 
  TreeNode* left; 
  TreeNode* right; 

  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};


class Solution{
  public: 
    bool isSameTree(TreeNode* one, TreeNode* two){

      if (!one && !two){
        return true;
      }
      
      if (one && !two || two && !one || one->val != two->val) {
        return false;
      }

      return isSameTree(one->left, two->left) && isSameTree(one->right, two->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subtree){

      if (!root) {
        return subtree == nullptr;
      }
       
      if (root->val == subtree->val){
       if (isSameTree(root, subtree) == false){
        return isSubtree(root->left, subtree) || isSubtree(root->right, subtree);
       }

       return true;
      } 

      return isSubtree(root->left, subtree) || isSubtree(root->right, subtree);
    }
};

