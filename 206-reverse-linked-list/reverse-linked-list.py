# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        perv = None
        temp = None

        while curr:
            temp = curr.next # storing next link
            curr.next = perv
            perv= curr
            curr = temp
        return perv
        