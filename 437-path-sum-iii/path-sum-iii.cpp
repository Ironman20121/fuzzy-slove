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
    map<long,int>mp;
    int count = 0;
    int pathSum(TreeNode* root, int targetSum) {
    std::function<void(TreeNode* ,int ,long)> dfs = [&](TreeNode* root,int targetSum, long perfix_sum){

        if(!root) return;
        perfix_sum+=root->val;
        if(mp.find(perfix_sum - targetSum)!=mp.end()){
            count +=mp[perfix_sum - targetSum];
        }
        mp[perfix_sum]++;
        dfs(root->left,targetSum,perfix_sum);
        dfs(root->right,targetSum,perfix_sum);
        mp[perfix_sum]--;

    };

    mp[0] = 1;
    dfs(root,targetSum,0);
    return count;


    }
};