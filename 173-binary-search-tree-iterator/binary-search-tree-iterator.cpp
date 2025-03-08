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
class BSTIterator {
public:
    vector<int> BSTlist;
    int Iterator=0;

    BSTIterator(TreeNode* root) {
        function<void(TreeNode*)> dfs = [&](TreeNode* root){
            if(!root){return;}
            dfs(root->left);
            BSTlist.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
    }
    
    int next() {
        int val = BSTlist[Iterator];
        Iterator++;
        return val;
    }
    
    bool hasNext() {
        return  Iterator < BSTlist.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */