Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7]
Output: [1, 5, 7, 8, 9]

struct valueCompare {
  bool operator()(const ListNode *x, const ListNode *y) { return x->value > y->value }
};

static ListNode *merge(const vector<ListNode *> &lists) {
  priority_queue<ListNode *, vector<ListNode *>, valueCompare> minHeap;

  for(auto root : lists){
    if(root != NULL){
      minHeap.push(root);
    }
  }

  // take the smallest (top) element form the min-heap and add it to the result;
  // if the top element has a next element add it to the heap
  ListNode *resultHead = nullptr, *resultTail = nullptr;
  while (!minHeap.empty()) {
    ListNode *node = minHeap.top();
    minHeap.pop();
    if (resultHead == nullptr) {
      resultHead = resultTail = node;
    } else {
      resultTail->next = node;
      resultTail = resultTail->next;
    }
    if (node->next != nullptr) {
      minHeap.push(node->next);
    }
  }

  return resultHead;
}

Time complexity #
Since we’ll be going through all the elements of all arrays and will be removing/adding one element to the heap in each step, the time complexity of the above algorithm will be O(N*logK), where ‘N’ is the total number of elements in all the ‘K’ input arrays.

Space complexity #
The space complexity will be O(K) because, at any time, our min-heap will be storing one number from all the ‘K’ input arrays.
