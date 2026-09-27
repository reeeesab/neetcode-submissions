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

    ListNode* reverse(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head && !head->next) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev  = dummy;
        ListNode* first = dummy;
        ListNode* temp;
        while(first){
            for(int i = 0; i<k; i++){
                if(first) first= first->next;
            }
            if(first){
                temp = first->next;
            }else{
                break;
            }
            ListNode* temp2 = prev->next;
            first->next = nullptr;
            prev->next = reverse(prev->next);
            temp2->next = temp;
            prev=temp2;
            first=temp2;
        }    

        return dummy->next;
    }
};
