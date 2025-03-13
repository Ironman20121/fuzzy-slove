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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int>ans;
        map<double,vector<int>>t;
        function<void(TreeNode*)>dfs =[&](TreeNode*root){
            if (!root)return;
                
                 dfs(root->right);
                t[abs(root->val - target)].push_back(root->val);
                // t[abs(root->val - target)].insert(t[abs(root->val -target)].end(),root->val);
                dfs(root->left);
               
        };
        
        dfs(root);
        for(auto&i:t){
            if (k==0)break;
            for(auto j:i.second){
                ans.insert(ans.end(),j);
                k--;
            }   
        }
        return ans;
    }
};