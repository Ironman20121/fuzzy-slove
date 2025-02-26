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
    int pairSum(ListNode* head) {
        ListNode *curr = head;
        int len =0; // n will even for sure
        map<int,int> t;
        //length
        while(curr){
            t[len] = curr->val;
            curr = curr->next;
            len++;
        }
        // cout<<"length :"<<len<<endl;
        // adding this keep orginal length rather than index

        // 6 nodes
        //7,6,5,4,2,1
        /*
        i =0 twin (6-1 -0)
        i = 5 =>7[0] :1[5] =8
        i =1 =>6[1]:2[4] = 8
        i = 2 =?5[2]:4[3] = 9
        */
        // for(auto &pair:t){
        //     cout <<pair.first<<":"<<pair.second<<endl;
        // }
       int max_of_all = 0;
       for(int i=0;i<(len/2);i++){
          if(max_of_all < t[i] + t[len-1-i]){
            max_of_all = t[i] + t[len-1-i];
            // cout<< t[i] << ","<<t[len-1-i]<<endl;
            // cout<< i << ","<<len-i<<endl;
          }

       }
        return max_of_all;
    
    }
};