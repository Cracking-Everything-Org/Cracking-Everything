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
        if(!head || !head->next)
            return true;
        else {
            stack<int> s1;
            ListNode* slow = head;
            ListNode* fast = slow;

            while(fast && fast->next) {
                s1.push(slow->val);
                slow = slow->next;
                fast = fast->next->next;
            }

            if(fast)
                slow = slow->next;

            while(slow) {
                int current = s1.top();
                if( s1.empty() || slow->val != current)
                    return false;
                s1.pop();
                slow = slow->next;
            }
        return true;
        }
    }
};
