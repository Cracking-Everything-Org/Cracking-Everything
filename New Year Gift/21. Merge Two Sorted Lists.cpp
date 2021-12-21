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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode(-1);
        ListNode* current = start;
        
        ListNode* flPointer = l1;
        ListNode* slPointer = l2;
        
        while (flPointer && slPointer) {
            if (flPointer->val <= slPointer->val) {
                ListNode* newNode = new ListNode(flPointer->val);
                current->next = newNode;
                current = newNode;
                flPointer = flPointer->next;
            } else {
                ListNode* newNode = new ListNode(slPointer->val);
                current->next = newNode;
                current = newNode;
                slPointer = slPointer->next;
            }
            
        }
        
        while (flPointer) {
            ListNode* newNode = new ListNode(flPointer->val);
            current->next = newNode;
            current = newNode;
            flPointer = flPointer->next;
        }
        
        while (slPointer) {
            ListNode* newNode = new ListNode(slPointer->val);
            current->next = newNode;
            current = newNode;
            slPointer = slPointer->next;
        }
        
        return start->next;
    }
};