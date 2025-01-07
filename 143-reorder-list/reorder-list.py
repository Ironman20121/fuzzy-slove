# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        #finding minding using slow and fast pointer
        slow,fast = head,head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        #rever 2nd half
        sec = slow.next
        perv = None
        slow.next = None # end of 1st list
        while sec:
            temp = sec.next
            sec.next = perv
            perv = sec
            sec = temp
        
        #merging two list
        first,sec = head,perv
        while sec:
            #storing as we are going break the link
            temp1 ,temp2 = first.next,sec.next
            #1st ele -> last ele
            first.next = sec
            #last ele -> 2nd ele
            sec.next = temp1
            #incrementing or moving next element
            first,sec = temp1,temp2

