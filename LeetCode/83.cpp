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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        if(!curr || !curr->next) return curr;
        while(curr && curr->next){
            if(curr->val == curr->next->val){
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            }
            else curr = curr->next;
        }
        return head;
    }
};
