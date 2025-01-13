# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:


        # we are dfs we are goint perorder NLR
        def dfs(root,currSum):

            if not root: return False

            currSum+=root.val
            # check if node is  leadnode
            if not root.right and not root.left:
                # it is  should return true of not if return false
                return currSum == targetSum
            # left fails it gooes to right
            return dfs(root.right,currSum) or dfs(root.left,currSum)

        
        return dfs(root,0)