/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode evenNum = ListNode(-2);
        ListNode oddNum = ListNode(-1);
        ListNode *evenhead =&evenNum;
        ListNode *oddhead =&oddNum;
        ListNode *eventail = evenhead;
        ListNode *oddtail =  oddhead;
        ListNode *curr = head;
        int index = 1;
        while(curr){
            if (index%2 ==0){
                eventail->next = curr;
                eventail = eventail->next;
                

            }
            else{
                oddtail->next = curr;
                oddtail = oddtail->next;

            }
            curr = curr->next;
            index++;
    
        }
        oddtail->next = evenhead->next;
        eventail->next =nullptr;
        return oddhead->next;

    }
};