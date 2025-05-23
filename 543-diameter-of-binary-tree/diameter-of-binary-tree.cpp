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
   
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)>dfs = [&](TreeNode* root){
            if(!root){return -1;}
            int left = dfs(root->left);
            int right = dfs(root->right);
            ans = max(ans,2 +left + right);
            return 1+max(left,right);
        };
        int val = dfs(root);
        return ans;
        
    }
};