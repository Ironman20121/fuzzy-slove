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
    int max_depth = 0;
    int maxDepth(TreeNode* root) {
        if (!root){return 0;}
        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);
        max_depth = max(max_depth,1 + left_max_depth+right_max_depth);
        
        return 1 + max(left_max_depth,right_max_depth);

    }
};