class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next) {
      if (slow == fast) break;
      slow = slow->next;
      fast = fast->next->next;
    }
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};