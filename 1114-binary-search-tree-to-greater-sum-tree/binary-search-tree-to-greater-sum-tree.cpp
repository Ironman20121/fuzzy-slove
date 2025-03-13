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
    TreeNode* bstToGst(TreeNode* root) {
        int Sum  =0;
        function<void(TreeNode *)>dfs =[&](TreeNode*root){
            if(!root)return;
            dfs(root->right);
            Sum+=root->val;
            root->val = Sum;
            dfs(root->left);
        };
        dfs(root);
        return root;
    }
};