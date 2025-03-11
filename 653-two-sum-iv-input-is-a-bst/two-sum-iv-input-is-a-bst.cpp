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
    bool findTarget(TreeNode* root, int k) {
       vector<int>treevals;
      
        function<void(TreeNode*)>dfs = [&](TreeNode *root){
            if(!root)return;
            dfs(root->left);
            treevals.push_back(root->val);
            cout<<root->val <<" ";
            dfs(root->right);
        };
        dfs(root);  //o(N) as ur traveling all nodes
        int left =0;
        int right = treevals.size()-1;
        while(left < right){ //as it is sorted you will get as soon as possible  o(N)
            if(treevals[left]+treevals[right]==k){return true;}
            if (treevals[left]+treevals[right]<k){left++;}
            if(treevals[left]+treevals[right]>k){right--;}
        }
        
        return false;
    } 

};