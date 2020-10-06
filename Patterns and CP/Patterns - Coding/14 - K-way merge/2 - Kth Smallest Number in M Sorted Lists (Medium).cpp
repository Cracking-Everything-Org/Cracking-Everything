Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
Output: 4
Explanation: The 5th smallest number among all the arrays is 4, this can be verified from the merged
list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7], K=3
Output: 7
Explanation: The 3rd smallest number among all the arrays is 7.

int findKthSmallest(const vector<vector<int>> &lists, int k) {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare>
      minHeap;

  // put the 1st element of each array in the min heap
  for (int i = 0; i < lists.size(); i++) {
    if (!lists[i].empty()) {
      minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
    }
  }

  // take the smallest (top) element form the min heap, if the running count is equal to k return
  // the number if the array of the top element has more elements, add the next element to the
  // heap
  int numberCount = 0, result = 0;
  while (!minHeap.empty()) {
    auto node = minHeap.top();
    minHeap.pop();
    result = node.first;
    if (++numberCount == k) {
      break;
    }
    node.second.second++;
    if (lists[node.second.first].size() > node.second.second) {
      node.first = lists[node.second.first][node.second.second];
      minHeap.push(node);
    }
  }

  return result;
}

Time complexity #
Since we’ll be going through at most ‘K’ elements among all the arrays, and we will remove/add one element in the heap in each step, the time complexity of the above algorithm will be O(K*logM) where ‘M’ is the total number of input arrays.

Space complexity #
The space complexity will be O(M) because, at any time, our min-heap will be storing one number from all the ‘M’ input arrays.
