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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next== nullptr) return head;

        ListNode* prev= head;
        ListNode* temp= prev->next;

        while(temp!=nullptr){
            if(prev->val == temp->val){
                prev->next= temp->next;
                temp->next= nullptr;
                delete temp;
            }
            else{
                prev= prev->next;
                temp= temp->next;
            }
            temp=prev->next;
            
        }
        return head;
    }
};