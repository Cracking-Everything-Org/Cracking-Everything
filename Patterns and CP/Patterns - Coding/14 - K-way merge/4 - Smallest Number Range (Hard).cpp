Given ‘M’ sorted arrays, find the smallest range that includes at least one number from each of the ‘M’ lists.

Example 1:

Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
Output: [4, 7]
Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
Example 2:

Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
Output: [9, 12]
Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3.


pair<int, int> findSmallestRange(const vector<vector<int>> &lists) {
  // we will store the actual number, list index and element index in the heap
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare>
      minHeap;

  int rangeStart = 0, rangeEnd = numeric_limits<int>::max(),
      currentMaxNumber = numeric_limits<int>::min();
  // put the 1st element of each array in the min heap
  for (int i = 0; i < lists.size(); i++) {
    if (!lists[i].empty()) {
      minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
      currentMaxNumber = max(currentMaxNumber, lists[i][0]);
    }
  }

  // take the smallest (top) element form the min heap, if it gives us smaller range, update the
  // ranges if the array of the top element has more elements, insert the next element in the heap
  while (minHeap.size() == lists.size()) {
    auto node = minHeap.top();
    minHeap.pop();
    if (rangeEnd - rangeStart > currentMaxNumber - node.first) {
      rangeStart = node.first;
      rangeEnd = currentMaxNumber;
    }
    node.second.second ++;
    if (lists[node.second.first].size() > node.second.second) {
      node.first = lists[node.second.first][node.second.second];
      minHeap.push(node);  // insert the next element in the heap
      currentMaxNumber = max(currentMaxNumber, node.first);
    }
  }

  return make_pair(rangeStart, rangeEnd);
}

Time complexity #
Since, at most, we’ll be going through all the elements of all the arrays and will remove/add one element in the heap in each step, the time complexity of the above algorithm will be O(N*logM) where ‘N’ is the total number of elements in all the ‘M’ input arrays.

Space complexity #
The space complexity will be O(M) because, at any time, our min-heap will be store one number from all the ‘M’ input arrays.
