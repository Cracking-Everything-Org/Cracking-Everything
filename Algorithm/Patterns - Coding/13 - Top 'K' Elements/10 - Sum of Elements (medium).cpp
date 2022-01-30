Given an array, find the sum of all numbers between the K1’th and K2’th smallest elements of that array.

Example 1:

Input: [1, 3, 12, 5, 15, 11], and K1=3, K2=6
Output: 23
Explanation: The 3rd smallest number is 5 and 6th smallest number 15. The sum of numbers coming
between 5 and 15 is 23 (11+12).
Example 2:

Input: [3, 5, 8, 7], and K1=1, K2=4
Output: 12
Explanation: The sum of the numbers between the 1st smallest number (3) and the 4th smallest
number (8) is 12 (5+7).


int findSumOfElements(const vector<int> &nums, int k1, int k2) {
  priority_queue<int, vector<int>, numCompare> minHeap;

  // insert all numbers to the min heap
  for (int i = 0; i < nums.size(); i++) {
    minHeap.push(nums[i]);
  }

  // remove k1 small numbers from the min heap
  for (int i = 0; i < k1; i++) {
    minHeap.pop();
  }

  int elementSum = 0;
  // sum next k2-k1-1 numbers
  for (int i = 0; i < k2 - k1 - 1; i++) {
    elementSum += minHeap.top();
    minHeap.pop();
  }

  return elementSum;
}

Time complexity #
Since we need to put all the numbers in a min-heap, the time complexity of the above algorithm will be O(N*logN) where ‘N’ is the total input numbers.

Space complexity #
The space complexity will be O(N), as we need to store all the ‘N’ numbers in the heap.
