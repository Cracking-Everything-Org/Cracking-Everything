Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle.

ListNode *findCycleStart(ListNode *head) {
  int cycleLength = 0;
  // find the LinkedList cycle
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {  // found the cycle
      cycleLength = calculateCycleLength(slow);
      break;
    }
  }

  return findStart(head, cycleLength);
}


int calculateCycleLength(ListNode *slow) {
  ListNode *current = slow;
  int cycleLength = 0;
  do {
    current = current->next;
    cycleLength++;
  } while (current != slow);

  return cycleLength;
}

ListNode *findStart(ListNode *head, int cycleLength) {
  ListNode *pointer1 = head, *pointer2 = head;
  // move pointer2 ahead 'cycleLength' nodes
  while (cycleLength > 0) {
    pointer2 = pointer2->next;
    cycleLength--;
  }

  // increment both pointers until they meet at the start of the cycle
  while (pointer1 != pointer2) {
    pointer1 = pointer1->next;
    pointer2 = pointer2->next;
  }

  return pointer1;
}

Time Complexity #
As we know, finding the cycle in a LinkedList with ‘N’ nodes and also finding the length of the cycle requires O(N). Also, as we saw in the above algorithm, we will need O(N) to find the start of the cycle. Therefore, the overall time complexity of our algorithm will be O(N).

Space Complexity #
The algorithm runs in constant space O(1).
