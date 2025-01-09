# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:

        if not root: return None

        if key < root.val:
            root.left = self.deleteNode(root.left,key)
        elif key > root.val:
            root.right = self.deleteNode(root.right,key)
        
        else :
            if not root.right: return root.left
            elif not root.left : return root.right
            else :
                #finding mining val
                min_Val = self.findMin(root.right)
                # replacing it 
                root.val = min_Val.val
                # delete child which is replaced as root 
                root.right = self.deleteNode(root.right,min_Val.val)
        return root 


    def findMin(self,root):
        curr = root
        while curr and curr.left:
            curr = curr.left
        return curr