# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        # def dfs(root):
        #     if not root: return None

        #     temp = root.left
        #     root.left = root.right
        #     root.right = temp
        #     dfs(root.left)  
        #     dfs(root.right)
        # dfs(root)
        
        if not root: return None
        que = deque()
        
        if root: que.append(root)

        while len(que) > 0:
            for i in range(len(que)):
                curr = que.popleft()
                if curr.right:que.append(curr.right)
                if curr.left: que.append(curr.left)
                temp = curr.left
                curr.left = curr.right
                curr.right = temp


        return root

