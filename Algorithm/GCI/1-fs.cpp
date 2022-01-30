class LinkedListCycle {
 public:
  static bool hasCycle(ListNode *head) { 
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
      if (slow == fast) return true;
      slow = slow->next;
      fast = fast->next->next;
    }
    return false;
  }
};