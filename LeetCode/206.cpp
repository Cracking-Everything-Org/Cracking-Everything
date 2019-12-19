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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        while(second){
            ListNode* temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        head->next=NULL;
        head = first;
        return first;
    }
};
