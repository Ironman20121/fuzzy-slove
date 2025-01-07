# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # reversing ll and deleting ele and reversing it again
        curr = head
        perv = None
        
        while curr:
            temp = curr.next
            curr.next = perv
            perv = curr
            curr = temp
        
        curr = perv
        
        if n==1:
            perv = perv.next
        else :
            count = n-2
            while count:
                count = count -1
                curr = curr.next
            curr.next = curr.next.next
        
        curr =  perv

        while curr:
            print(curr.val,end="->")
            curr = curr.next
       
        
        curr = perv
        perv2 = None
        temp = None 

        while curr:
            temp  = curr.next
            curr.next = perv2
            perv2 = curr
            curr = temp
        
        curr = perv2
        print("end")

        # while curr:
          
        #     print(curr.val,end="->")
        #     curr = curr.next

        return perv2

        


        

        