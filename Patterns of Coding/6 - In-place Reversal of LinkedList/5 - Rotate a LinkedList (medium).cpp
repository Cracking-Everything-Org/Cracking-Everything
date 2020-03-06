Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the right by ‘k’ nodes.

ListNode *rotate(ListNode *head, int rotations) {
  if (head == nullptr || head->next == nullptr || rotations <= 0) {
    return head;
  }

  // find the length and the last node of the list
  ListNode *lastNode = head;
  int listLength = 1;
  while (lastNode->next != nullptr) {
    lastNode = lastNode->next;
    listLength++;
  }

  lastNode->next = head;    // connect the last node with the head to make it a circular list
  rotations %= listLength;  // no need to do rotations more than the length of the list
  int skipLength = listLength - rotations;
  ListNode *lastNodeOfRotatedList = head;
  for (int i = 0; i < skipLength - 1; i++) {
    lastNodeOfRotatedList = lastNodeOfRotatedList->next;
  }

  // 'lastNodeOfRotatedList.next' is pointing to the sub-list of 'k' ending nodes
  head = lastNodeOfRotatedList->next;
  lastNodeOfRotatedList->next = nullptr;
  return head;
}

Time complexity #
The time complexity of our algorithm will be O(N) where ‘N’ is the total number of nodes in the LinkedList.

Space complexity #
We only used constant space, therefore, the space complexity of our algorithm is O(1).
