class Solution {
public:
    /*
        1 approach: llamadas recursivas, sin usar memoria, eso hace que sea time o(n log n), space o(log n) for the recursive stack
        2 approach: utilizando una lista, eso hace que el tiempo sea lineal pero el espacio aumente a lineal
        3 approach: usar Fast and Slow pointers, pararme en el medio e ir dividiendo la linkedlist time O(n),
                    space O(log n) en el recursive stack porque esta balanceado, si no O(n)
    */

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        if (prev == nullptr) return root;
        prev->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
