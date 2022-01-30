Given the head of a Singly LinkedList, reverse the LinkedList. Write a function to return the new head of the reversed LinkedList.

ListNode *reverse(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode *current = head;      // current node that we will be processing
  ListNode *previous = nullptr;  // previous node that we have processed
  ListNode *next = nullptr;      // will be used to temporarily store the next node

  while (current != nullptr) {
    next = current->next;      // temporarily store the next node
    current->next = previous;  // reverse the current node
    previous = current;  // before we move to the next node, point previous to the current node
    current = next;      // move on the next node
  }
  // after the loop current will be pointing to 'null' and 'previous' will be the new head
  return previous;
}

Time complexity #
The time complexity of our algorithm will be O(N) where ‘N’ is the total number of nodes in the LinkedList.

Space complexity #
We only used constant space, therefore, the space complexity of our algorithm is O(1).
