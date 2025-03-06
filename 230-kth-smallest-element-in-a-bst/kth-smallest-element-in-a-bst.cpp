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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted_list_from_tree ;

        function<void(TreeNode*)> dfs =[&](TreeNode *root){
            if (!root){return;}
            // if BST then it sort inorder LNR
            dfs(root->left);
            sorted_list_from_tree.push_back(root->val);
            dfs(root->right);
        }; 
        // i GOT THIS QUESTION ORACAL INTERVIEW I **** IT AND SORTED IT AGAIN I FORGET THAT BST  DFS WILL GIVE IN ORDER SO IT ALREADY F************ YOU
        dfs(root);
        for(auto &i:sorted_list_from_tree){cout <<i<<" ";}
        cout<<endl;
        return sorted_list_from_tree[k-1];
    }
};