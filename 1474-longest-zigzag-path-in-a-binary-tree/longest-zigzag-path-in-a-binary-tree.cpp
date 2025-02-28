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
    int path_length = 0;
    int longestZigZag(TreeNode* root) {
    std::function<void(TreeNode* ,bool,int)>dfs = [&](TreeNode* root,int go_left,int steps){
        if(!root){return ;}
        path_length = max(path_length,steps);
        if(go_left){
            dfs(root->left,false,steps +1);
            dfs(root->right,true,1);

        }
        else{
            dfs(root->left,false,1);
            dfs(root->right,true,steps +1);
        }
    };

       dfs(root,true,0);
       return path_length; 
    }
};