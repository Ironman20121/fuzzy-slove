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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if (!root1 && !root2){return false;}
        map<int,bool>root2vals;
        function<void(TreeNode*)>dfstore = [&](TreeNode*root){
            if(!root){return;}
            dfstore(root->left);
            root2vals[root->val] = true;
            dfstore(root->right);
        };
        dfstore(root2);
        
        bool check = false;
        function<bool(TreeNode*)>dfs = [&](TreeNode*root){
            if(!root){return false; ;}
            
            dfs(root->left);
            if(root2vals[target-root->val]){
                check = true;
            }
            dfs(root->right);
            return check;
        };
        return  dfs(root1);
    }
};