/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //O(n) space
/*class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> stk;
        while (fast && fast->next) {
            stk.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;
        while(slow){
            int toCompare = stk.top();
            stk.pop();
            if (slow->val != toCompare) return false;
            slow = slow->next;
        }
        return true;
    }
};*/

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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;

        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        ListNode* first = head;
        ListNode* second = secondHalfStart;
        bool result = true;
        while (result && second) {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
