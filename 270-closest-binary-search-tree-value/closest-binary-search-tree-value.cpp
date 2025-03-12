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
    int closestValue(TreeNode* root, double target) {
        int ans = 10e6;
        function<void(TreeNode*)>dfs = [&](TreeNode* root){
            if (!root)return;
            

            if (abs(root->val - target)  < abs(ans- target) ){ans=root->val;}
            if(abs(root->val - target)  == abs(ans- target)){
                 if (ans >  root->val) ans = root->val;
                 }
             dfs(root->left);
                
             dfs(root->right);
      
             
        };
        dfs(root);
        return ans;
    }
};