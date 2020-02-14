Given an unsorted array of numbers, find the ‘K’ largest numbers in it.

Note: For a detailed discussion about different approaches to solve this problem, take a look at Kth Smallest Number.

Example 1:

Input: [3, 1, 5, 12, 2, 11], K = 3
Output: [5, 12, 11]
Example 2:

Input: [5, 12, 11, -1, 12], K = 3
Output: [12, 11, 12]

struct greater {
  bool operator()(const int& a, const int& b) const { return a > b; }
};
static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
  // put first 'K' numbers in the min heap
  vector<int> minHeap(nums.begin(), nums.begin() + k);
  make_heap(minHeap.begin(), minHeap.end(), greater());

  // go through the remaining numbers of the array, if the number from the array is bigger than
  // the top (smallest) number of the min-heap, remove the top number from heap and add the number
  // from array
  for (int i = k; i < nums.size(); i++) {
    if (nums[i] > minHeap.front()) {
      pop_heap(minHeap.begin(), minHeap.end(), greater());
      minHeap.pop_back();
      minHeap.push_back(nums[i]);
      push_heap(minHeap.begin(), minHeap.end(), greater());
    }
  }

  // the heap has the top 'K' numbers
  return minHeap;
}

Time complexity #
As discussed above, the time complexity of this algorithm is O(K*logK+(N-K)*logK), which is asymptotically equal to O(N*logK)

Space complexity #
The space complexity will be O(K) since we need to store the top ‘K’ numbers in the heap.
