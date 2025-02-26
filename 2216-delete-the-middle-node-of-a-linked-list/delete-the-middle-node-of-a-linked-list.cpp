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
    ListNode* deleteMiddle(ListNode* head) {
        // index is like array start with 0
        //  head == 0
        ListNode dummy = ListNode(-1,head);
        ListNode* curr = head;
        int length = 0;
        while (curr){
            curr = curr->next;
            length++;
        }
        if (length ==1) return nullptr;
        length/=2;
        length--;
        curr  = &dummy;
        
        while(length--){
            curr = curr->next;
        }
        curr = curr->next;
        if (curr->next){
        curr->next = curr->next->next;
        }
        else{curr->next = nullptr;}
        return dummy.next;

    }
};