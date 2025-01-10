# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
       if not root: return 0  
       que = deque()
       if root: que.append(root)
       depth =0
       while len(que) > 0:
            depth+=1
            for i in range(len(que)):
                curr = que.popleft()
                if curr.right:que.append(curr.right)
                if curr.left: que.append(curr.left)
       return depth 
