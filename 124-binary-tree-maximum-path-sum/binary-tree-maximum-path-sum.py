# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        # instead of max it glonbal we can play this 
        ans = [root.val]

        # base case will return 0 if it child is non 
        def dfs(root):
            if not root:return 0

            leftMax = dfs(root.left)
            rightMax = dfs(root.right)

            # if it -ve we need not return 
            leftMax = max(leftMax,0)
            rightMax = max(rightMax,0)

            # calcuating with childern or split
            #updating max is key
            ans[0] = max(ans[0],root.val+leftMax+rightMax)

            # return to parent you take either one of child not 2 both differnt paths 

            return root.val+max(leftMax,rightMax)
        dfs(root)
        return ans[0]




       
