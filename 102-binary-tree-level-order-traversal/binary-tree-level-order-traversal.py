# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levelArr = [] # tracking all level orders listss
        que = deque() #queue #FIFO
        if root:que.append(root) # base codition if root append it 
        level = 0 # tracking levels      
        while len(que) > 0: # queue is empty or not 
            #print(f"level {level}") 
            persent_level_list = [] #peresent_level_list
            for i in range(len(que)):  
                curr = que.popleft() # curr ele pop out 
                persent_level_list.append(curr.val)
                #checking for left child  
                if curr.left:que.append(curr.left) 
                #checking for right child 
                if curr.right:que.append(curr.right)
                #persent_level_list.append(curr.val)
            level +=1 
            levelArr.append(persent_level_list) #
        return levelArr
                



        