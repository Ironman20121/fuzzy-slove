# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:


        def bfs(root):
            treelist = []
            que = deque()
            if root:
                root.val = str(root.val)+"N" 
                que.append(root)

            while len(que) > 0:
                levellist =[]
                for i in range(len(que)):
                    curr = que.popleft()
                    if curr.left: 
                        curr.left.val = str(curr.left.val)+"L"
                        que.append(curr.left)
                    if curr.right : 
                        curr.right.val = str(curr.right.val)+"R"
                        que.append(curr.right)
                    
                    levellist.append(curr.val)
                treelist.append(levellist)
            return treelist
        treelist1 = bfs(p)
        treelist2 = bfs(q)

        # print(treelist1,treelist2,sep="\n")      
        return treelist1==treelist2          



