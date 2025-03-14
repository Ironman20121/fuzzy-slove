# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ## recursive solution 
        ## inorder LNR 
        ans = []
        def inorder(root):
            if not root: return 
            inorder(root.left) # left 
            ans.append(root.val) # val
            inorder(root.right) # r
        inorder(root)
        return ans






        