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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,map<int,vector<int>>>order;
        function<void(TreeNode*,int,int)>dfs =[&](TreeNode*root,int index,int row){
                if (!root)return;
                 order[index][row].push_back(root->val);
                 dfs(root->left,index-1,row+1);
                 dfs(root->right,index+1,row+1);      
        };
        dfs(root,0,0);
        vector<vector<int>>ans;
        for (auto& colPair : order) {
        vector<int> colVals;
        for (auto& rowPair : colPair.second) {
               colVals.insert(colVals.end(), rowPair.second.begin(), rowPair.second.end());

        }
            ans.push_back(colVals);
        }

        return ans;
    }
};