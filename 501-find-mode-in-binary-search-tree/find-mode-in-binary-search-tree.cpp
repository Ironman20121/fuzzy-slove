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
    vector<int> findMode(TreeNode* root) {
        map<int,int> t;
        function<void(TreeNode*)>dfs = [&](TreeNode*root){
            if(!root)return;
            dfs(root->left);
            t[root->val]++;
            dfs(root->right);
        };
        dfs(root);
        vector<int>ans;
        //find max;
        int maxi=0;
        for(auto i:t){
            if(i.second > maxi){maxi = i.second;}
        }
        for(auto i:t){
            if(i.second== maxi){ans.insert(ans.end(),i.first);}
        }
        return ans;
        
    }
};