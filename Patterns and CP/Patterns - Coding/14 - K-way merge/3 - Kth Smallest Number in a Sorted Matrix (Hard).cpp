Given an N * NN∗N matrix where each row and column is sorted in ascending order, find the Kth smallest element in the matrix.

Example 1:

Input: Matrix = [
    [2, 6, 8],
    [3, 7, 10],
    [5, 8, 11]
  ],
  K=5
Output: 7
Explanation: The 5th smallest number in the matrix is 7.


int findKthSmallest(vector<vector<int>> &matrix, int k) {
  int n = matrix.size();12
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare>
      minHeap;

  // put the 1st element of each row in the min heap
  // we don't need to push more than 'k' elements in the heap
  for (int i = 0; i < n && i < k; i++) {
    minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
  }

  // take the smallest element form the min heap, if the running count is equal to k return the
  // number if the row of the top element has more elements, add the next element to the heap
  int numberCount = 0, result = 0;
  while (!minHeap.empty()) {
    auto heapTop = minHeap.top();
    minHeap.pop();
    result = heapTop.first;
    if (++numberCount == k) {
      break;
    }

    heapTop.second.second++;
    if (n > heapTop.second.second) {
      heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
      minHeap.push(heapTop);
    }
  }
  return result;
}

Time complexity #
First, we inserted at most ‘K’ or one element from each of the ‘N’ rows, which will take O(min(K, N)). Then we went through at most ‘K’ elements in the matrix and remove/add one element in the heap in each step. As we can’t have more than ‘N’ elements in the heap in any condition, therefore, the overall time complexity of the above algorithm will be O(min(K, N) + K*logN).

Space complexity #
The space complexity will be O(N) because, in the worst case, our min-heap will be storing one number from each of the ‘N’ rows.
