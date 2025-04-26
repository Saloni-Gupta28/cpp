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
    int getLen(ListNode* head){
        ListNode* temp= head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len= getLen(head);
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(len<k){
            return head;
        }
        int pos=0;
        ListNode* prev=nullptr;
        ListNode*temp= head;

        while(pos<k){
            ListNode* forward=temp->next;
            temp->next= prev;
            prev= temp;
            temp= forward;
            pos++;
        }

        if(temp!=NULL){
            ListNode* recursive=reverseKGroup(temp, k);
            head->next= recursive;
        }
        return prev;

    }
};