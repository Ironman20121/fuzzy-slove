/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {

        typedef long long ll;
       
       function<bool(TreeNode*,ll,ll)>dfs = [&](TreeNode*root,ll left,ll right){
        if (!root){return true;}
        if( !(root->val > left && root->val < right) ){return false;}
        return dfs(root->left,left,root->val) &&  dfs(root->right,root->val,right);
       };
      return dfs(root,LONG_MIN,LONG_MAX);
    }
    
};