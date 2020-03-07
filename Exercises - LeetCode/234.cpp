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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> stk;
        while(fast && fast->next){
            stk.push(slow->val);
            slow= slow->next;
            fast= fast->next->next;
        }
        if(fast) slow = slow->next;
        while(slow){
            int toCompare = stk.top();
            stk.pop();
            if(slow->val != toCompare) return false;
            slow = slow->next;
        }
        return true;
    }
};
