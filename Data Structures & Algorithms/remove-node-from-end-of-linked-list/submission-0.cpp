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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev = dummy;
        ListNode* first = dummy;
       
        while(n--){
            first=first->next;
        }
        while(first && first->next){
            prev=prev->next;
            first=first->next;
        }

        prev->next=prev->next->next;
        return dummy->next;
    }
};
