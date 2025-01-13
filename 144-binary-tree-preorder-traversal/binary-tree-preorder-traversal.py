# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        stack = []
        ans = []
        # perorder -> N-L-R

        curr = root

        # if curr is not null or stack is no empty  
        while curr or stack:

            # if curr is platform    
            if curr:
                #Node or root 
                ans.append(curr.val)
                # storing right of stack
                if curr.right : 
                    stack.append(curr.right)
                # iteratt to next
                curr = curr.left

            # end of lift then we are pop right node to stack
            else : curr = stack.pop()

        return ans
            





        