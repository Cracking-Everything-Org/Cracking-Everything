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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return ;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode* first = head;
        ListNode* second = prev;
        
        while (second->next) {
            next = first->next;
            first->next = second;
            first = next;
            
            next = second->next;
            second->next = first;
            second = next;
        }
    }
};