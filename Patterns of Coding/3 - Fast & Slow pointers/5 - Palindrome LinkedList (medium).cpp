Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.

Your algorithm should use constant space and the input LinkedList should be in the original form once the algorithm is finished. The algorithm should have O(N) time complexity where ‘N’ is the number of nodes in the LinkedList.

Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
Output: true

Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
Output: false

bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    // find middle of the LinkedList
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *headSecondHalf = reverse(slow);  // reverse the second half
    ListNode *copyHeadSecondHalf =
        headSecondHalf;  // store the head of reversed part to revert back later

    // compare the first and the second half
    while (head != nullptr && headSecondHalf != nullptr) {
      if (head->value != headSecondHalf->value) {
        break;  // not a palindrome
      }
      head = head->next;
      headSecondHalf = headSecondHalf->next;
    }

    reverse(copyHeadSecondHalf);                         // revert the reverse of the second half
    if (head == nullptr || headSecondHalf == nullptr) {  // if both halves match
      return true;
    }
    return false;
  }

 private:
  static ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    while (head != nullptr) {
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }

  Time complexity #
  The above algorithm will have a time complexity of O(N) where ‘N’ is the number of nodes in the LinkedList.

  Space complexity #
  The algorithm runs in constant space O(1).
