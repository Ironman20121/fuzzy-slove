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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        function<void(TreeNode*)>dfs = [&](TreeNode *root){
            if(!root)return;
            dfs(root->left);
            if (root->val >= low && root->val <=high){ans+=root->val;}
            dfs(root->right);
        };
        dfs(root);
        return ans;
        
    }
};