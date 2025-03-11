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
       std::function<bool(TreeNode*, int)> binarySearch = [&](TreeNode* root, int complement) {
            if (!root) {
                return false;
            }
            if (complement == root->val) {
                return true;
            } else if (complement < root->val) {
                return binarySearch(root->left, complement);
            } else {
                return binarySearch(root->right, complement);
            }
        };

        std::function<bool(TreeNode*)> inorderTraversal = [&](TreeNode* root) {
            if (!root) {
                return false;
            }
            if (inorderTraversal(root->left)) {
                return true;
            }
            if (binarySearch(root2, target - root->val)) {
                return true;
            }
            return inorderTraversal(root->right);
        };

        return inorderTraversal(root1);
    }
};