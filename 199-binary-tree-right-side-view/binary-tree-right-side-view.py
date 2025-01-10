# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        que = deque()
        if root : que.append(root)

        while len(que)>0:
            plevel = [] # level list left and right always 
            for i in range(len(que)):
                ele = que.popleft()
                if ele.left: # here we can avoid this 
                    que.append(ele.left)
                if ele.right:
                    que.append(ele.right)
                plevel.append(ele.val)
            ans.append(plevel[-1])
        return ans
            
        