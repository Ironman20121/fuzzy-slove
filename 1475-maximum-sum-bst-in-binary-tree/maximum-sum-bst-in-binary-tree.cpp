
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        struct Bstinfo{
            bool isbst;int mini;int maxi;int sum;
        };
        int maxsum = 0;
    function<Bstinfo(TreeNode*, int&)> bup = [&](TreeNode* root, int& maxsum) {
        if (!root) {
            return Bstinfo{true, INT_MAX, INT_MIN, 0}; 
        }
        Bstinfo leftinfo = bup(root->left, maxsum);
        Bstinfo rightinfo = bup(root->right, maxsum);
        Bstinfo currinfo;
        currinfo.sum = root->val + leftinfo.sum + rightinfo.sum;

        if (leftinfo.isbst && rightinfo.isbst && root->val > leftinfo.maxi && root->val < rightinfo.mini) {
            currinfo.isbst = true;
            currinfo.mini = (root->left) ? leftinfo.mini : root->val;
            currinfo.maxi = (root->right) ? rightinfo.maxi : root->val; 
            maxsum = max(maxsum, currinfo.sum);
        } else {
            currinfo.isbst = false;
        }
        return currinfo;
    };
    bup(root, maxsum);
    return maxsum;
        
    }
};