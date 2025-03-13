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
        function<void(TreeNode*)>dfsbst = [&](TreeNode*root){
            if(!root)return;
            if(root->val > p->val){
                ans = root;
                dfsbst(root->left);
            }
            else {dfsbst(root->right);}
        };

        dfsbst(root);
        return ans;
    }
};