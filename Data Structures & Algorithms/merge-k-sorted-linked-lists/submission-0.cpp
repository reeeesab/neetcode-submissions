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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* ptrDummy = dummy;
        ListNode* ptrList1 = list1;
        ListNode* ptrList2 = list2;

        while(ptrList1 && ptrList2){
            if(ptrList1->val>ptrList2->val){
                ptrDummy->next = ptrList2;
                ptrList2 = ptrList2 -> next;

            }else{
                ptrDummy->next = ptrList1;
                ptrList1 = ptrList1 -> next;
            }

            ptrDummy = ptrDummy->next;
        }

        if(!ptrList1) ptrDummy->next = ptrList2;
        if(!ptrList2) ptrDummy->next = ptrList1;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        ListNode* first =  lists[0];
        for(int i = 1; i<lists.size(); i++){
            first = mergeTwoLists(first, lists[i]);
        }
        return first;
    }
};
