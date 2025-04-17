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
    ListNode* solveUsingRecursion(ListNode* curr, ListNode*prev){
        if(curr==nullptr){
            return prev;
        }
       
        ListNode* forward= curr->next;
        curr->next= prev;
        prev= curr;
        curr= forward;
      return solveUsingRecursion(curr, prev);
    }
public:
    ListNode* reverseList(ListNode* head) {
     ListNode* curr= head;
     ListNode* prev= nullptr;
    ListNode* ans= solveUsingRecursion(curr, prev);
    return ans;
        
    }
};