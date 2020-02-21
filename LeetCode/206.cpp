/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

 ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }


 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* start = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return start;
    }
};
