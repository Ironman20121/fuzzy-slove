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
    int minDiffInBST(TreeNode* root) {
        TreeNode* perv = nullptr;
        int mini = 10e6;
        function<void(TreeNode*)>dfs = [&](TreeNode *root){
            if (!root)return;
            dfs(root->left);
            if(perv){ mini = min(mini,abs(root->val - perv->val));}
            perv = root;
            dfs(root->right);
        };
        dfs(root);
        return mini;
        
    }
};