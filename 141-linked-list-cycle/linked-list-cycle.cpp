/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (head==nullptr){return false;}
        ListNode *fast = head->next;
        ListNode *slow = head;
    
        // to identify if Linked list as cycle we need fast and slow pointer techiniq one run double fast will meet at same point in n times
        while (slow->next !=nullptr && fast!=nullptr){

            if (fast==slow){
                return true;
            }
            else if (fast->next==nullptr){
                return false;
            }
            else{
fast = fast->next->next;
                slow = slow->next;
            }

        }




        return false;
    }
};