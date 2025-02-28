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
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q ;
        q.push(root);
        // util q is mot empty
        int level = 1;
        int max_sum = -1e9;
        int max_index = 0;
        while(!q.empty()){
            vector<int>plist;
            int qsize = q.size();
          
            for(int i=0;i<qsize;i++){
                //q is FIFO
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left){q.push(curr->left);}
                if(curr->right){q.push(curr->right);}
                plist.push_back(curr->val);
            }
            int level_sum =0;
            for(int i=0;i<plist.size();i++){
                level_sum+=plist[i];
            }
            if(max_sum < level_sum){
                max_sum = level_sum;
                max_index = level;
            }
            level++;

        }
        return max_index;

    }
};