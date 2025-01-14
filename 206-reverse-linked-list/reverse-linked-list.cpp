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
    ListNode* reverseList(ListNode* head) {

        ListNode *curr = head;
        ListNode *temp = nullptr;
        ListNode *perv  = nullptr;

        while (curr != nullptr){
            // storing because we r going change it 
            temp = curr->next;
 // now we are  pointing perv pointer which help in revering ll
            curr->next = perv;
            // once it pointerd we can perv to where curr persent 
            perv = curr;
            // now increment curr
            curr = temp;
        }
        // return new head 
        return perv;
    }
};