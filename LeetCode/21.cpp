/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0),
        ListNode* cur = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if(l2) cur->next = l2;
        if(l1) cur->next = l1;
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
