class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *perv = nullptr;
        TreeNode *ans  = nullptr;
        function<void(TreeNode*)>dfs = [&](TreeNode*root){
            if(!root)return;
            dfs(root->left);
            if(perv == p){ans=root;}
            perv=root;
            dfs(root->right);
        };
        dfs(root);
        return ans;
    }
};