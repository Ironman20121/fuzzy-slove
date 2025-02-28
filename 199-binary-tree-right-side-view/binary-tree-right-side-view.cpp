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
    vector<int> rightSideView(TreeNode* root) {
        if (!root){return vector<int>{};}
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            vector<int>plist;
            int q_size = q.size();
            for(int i=0;i<q_size;++i){
                TreeNode *curr = q.front();
                q.pop();
                plist.push_back(curr->val);
                if (curr->left){q.push(curr->left);}
                if (curr->right){q.push(curr->right);}
            }
            //pushing last element is key usally we store right elements in plist rest all is bfs
            ans.push_back(plist[plist.size()-1]);
        }
    return ans;
    }
    
};