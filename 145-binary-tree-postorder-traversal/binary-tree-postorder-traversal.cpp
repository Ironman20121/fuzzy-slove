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
    vector<int> postorderTraversal(TreeNode* root) {
        //LNR -> inorder 
        //NLR -> per order
        //LRN -> post order
        vector <int>ans;
        function <void(TreeNode *)> dfs =[&](TreeNode* root){
            if(!root){return;}
            dfs(root->left);
            dfs(root->right);
            ans.push_back(root->val);
        };
        dfs(root);
        return ans;
    }
};