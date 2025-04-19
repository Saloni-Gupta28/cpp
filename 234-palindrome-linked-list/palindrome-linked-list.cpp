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
    ListNode* getMiddle(ListNode* head, ListNode* &middlePrev){
        ListNode* slow= head;
        ListNode* fast= head;

        while(fast!=nullptr){
            fast= fast->next;
            if(fast!=nullptr){
                fast=fast->next;
                middlePrev= slow;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* reverseList(ListNode* prev, ListNode* curr){
        while(curr!=nullptr){
            ListNode* forward= curr->next;
            curr->next= prev;
            prev=curr;
            curr= forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr) {
            return true;
        }
        if(head->next==nullptr) {
            return true;
        }

        ListNode* middlePrev= nullptr;
        ListNode* firstHalf= head;
        ListNode* middle = getMiddle(head, middlePrev);
        middlePrev->next= nullptr;

        ListNode* prev= nullptr;
        ListNode* curr= middle;
        ListNode* secondHalf = reverseList(prev,curr);

        ListNode* tempHead1= firstHalf;
        ListNode* tempHead2= secondHalf;
        while(tempHead1 !=nullptr){
            if(tempHead1 ->val != tempHead2 ->val){
                return false;
            }
            else{
                tempHead1= tempHead1->next;
                tempHead2= tempHead2->next;
            }
        }
        return true;
    }
};