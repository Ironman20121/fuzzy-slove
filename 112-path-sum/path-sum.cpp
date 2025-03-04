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
    bool hasPathSum(TreeNode* root, int targetSum) {
        std::function<bool(TreeNode*,int,int)> dfs = [&](TreeNode* root, int target ,int presentSum){
            if (!root){return false;}
            presentSum+=root->val;
            if(!root->left && !root->right){
                if(presentSum == target){return true; }
            }
            if( dfs(root->left,target,presentSum)){return true;}
            if(dfs(root->right,target,presentSum)){
            return true;
            }
            presentSum-=root->val;
            return false;
        };
      
        return dfs(root,targetSum,0);

    }
};