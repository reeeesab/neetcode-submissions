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
    void reorderList(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head->next;
       ListNode* prev = nullptr;

       while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
       }

       ListNode* first = head;
       ListNode* second = slow->next;
       slow->next=nullptr;

       while(second){
        ListNode* temp = second->next;
        second->next = prev;
        prev=second;
        second=temp;
       }

       second=prev;

       while(second){
        ListNode* firstTemp = first->next;
        ListNode* secondTemp = second->next;

        first->next=second;
        second->next=firstTemp;
        first=firstTemp;
        second=secondTemp;
       }

    }
};
