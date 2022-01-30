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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while(n > 0) {
            fast = fast->next;
            n--;
        }

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // DEBO LIBERAR LA MEMORIA
        //ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        //delete toDelete;
        return dummy->next;
    }
};
