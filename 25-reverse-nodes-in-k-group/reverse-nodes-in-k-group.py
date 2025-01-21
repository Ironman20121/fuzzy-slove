# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        dummy = ListNode(0,head)
        groupPrev = dummy

        while True:

            kth =self.kthNode(groupPrev,k)
            if not kth:
                break
            groupNext = kth.next

            perv,curr = kth.next,groupPrev.next

            # we are reversing up to next group
            while curr!=groupNext:
                tmp = curr.next
                curr.next = perv
                perv = curr
                curr = tmp

            # we should inc but not miss link kth
            tmp =groupPrev.next
            groupPrev.next = kth
            groupPrev = tmp

        return dummy.next        

    


    def kthNode(self,curr,k):
        while curr and k >0:
            curr = curr.next
            k-=1
        return curr
