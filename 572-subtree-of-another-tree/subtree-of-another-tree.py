# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sameTree(self,p,q):
            if not p and not q: return True
            if p and q and p.val==q.val :
                # if root val is equal we recursivly checking left and right part of it 
                return (self.sameTree(p.left,q.left)) and (self.sameTree(p.right,q.right))
            return False
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot: return True # if subtree is null it sub set
        if not root : return False # reverse not possibel
        #tree -> recurssion
        # check it main root tree matching 
        if self.sameTree(subRoot,root):return True
        # if check either leftsub or right sub should match if not  it will return False
        return (self.isSubtree(root.left,subRoot)) or (self.isSubtree(root.right,subRoot))


        
        
