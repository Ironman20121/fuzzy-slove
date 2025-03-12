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
    int getMinimumDifference(TreeNode* root) {
        int mini = 10e6;
        vector<int>arr ;
        function<void(TreeNode*)> dfs = [&](TreeNode *root){
            if(!root )return ;
            dfs(root->left);
            arr.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        int j=0;
        for(int i=1;i<arr.size();i++){
            mini= min(mini,arr[i] - arr[j]);
            j++;
        }
        return mini;
    }
};