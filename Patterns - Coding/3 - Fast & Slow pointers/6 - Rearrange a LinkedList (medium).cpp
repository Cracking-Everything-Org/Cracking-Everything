Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes from the second half of the LinkedList are inserted alternately to the nodes from the first half in reverse order. So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.

Your algorithm should not use any extra space and the input LinkedList should be modified in-place.

void reorder(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return;
  }

  // find the middle of the LinkedList
  ListNode *slow = head, *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // slow is now pointing to the middle node
  ListNode *headSecondHalf = reverse(slow);  // reverse the second half
  ListNode *headFirstHalf = head;

  // rearrange to produce the LinkedList in the required order
  while (headFirstHalf != nullptr && headSecondHalf != nullptr) {
    ListNode *temp = headFirstHalf->next;
    headFirstHalf->next = headSecondHalf;
    headFirstHalf = temp;

    temp = headSecondHalf->next;
    headSecondHalf->next = headFirstHalf;
    headSecondHalf = temp;
  }

  // set the next of the last node to 'null'
  if (headFirstHalf != nullptr) {
    headFirstHalf->next = nullptr;
  }
}

ListNode *reverse(ListNode *head) {
  ListNode *prev = nullptr;
  while (head != nullptr) {
    ListNode *next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

Time Complexity #
The above algorithm will have a time complexity of O(N) where ‘N’ is the number of nodes in the LinkedList.

Space Complexity #
The algorithm runs in constant space O(1).
