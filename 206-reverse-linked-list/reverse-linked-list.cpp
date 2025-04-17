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
     if(head==nullptr) return head;
        ListNode* curr= head;
         ListNode* prevv = nullptr;
        

        while(curr!=nullptr){
            ListNode* forward = curr->next;
           
            curr->next= prevv;
            prevv=curr;
            curr= forward;
            
        }

      return prevv;
        
    }
};