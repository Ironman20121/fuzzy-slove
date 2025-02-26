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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf_nodes1,leaf_nodes2 ;
        //recursive lamda function  usally we don't need std::function auto will take care but as it is recusrsive we need define types before so that compiler will takae care of errors return type is void but give function argumetns is key ;
        
        std::function<void(TreeNode*, std::vector<int>&)> rec_tree = [&](TreeNode *root,vector<int>&leaf_nodes){
            if(!root){return;}

             rec_tree(root->left,leaf_nodes);
             if(root->left == nullptr && root->right ==nullptr){
                leaf_nodes.push_back(root->val);
             }
             rec_tree(root->right,leaf_nodes);
        };


        rec_tree(root1,leaf_nodes1);
        rec_tree(root2,leaf_nodes2);

        return (leaf_nodes1==leaf_nodes2);


    }
};