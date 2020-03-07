Given two sorted arrays in descending order, find ‘K’ pairs with the largest sum where each pair consists of numbers from both the arrays.

Example 1:

Input: L1=[9, 8, 2], L2=[6, 3, 1], K=3
Output: [9, 3], [9, 6], [8, 6]
Explanation: These 3 pairs have the largest sum. No other pair has a sum larger than any of these.
Example 2:

Input: L1=[5, 2, 1], L2=[2, -1], K=3
Output: [5, 2], [5, -1], [2, 2]

vector<pair<int, int>> findKLargestPairs(const vector<int> &nums1, const vector<int> &nums2, int k) {
  vector<pair<int, int>> minHeap;
  for (int i = 0; i < nums1.size() && i < k; i++) {
    for (int j = 0; j < nums2.size() && j < k; j++) {
      if (minHeap.size() < k) {
        minHeap.push_back(make_pair(nums1[i], nums2[j]));
        push_heap(minHeap.begin(), minHeap.end(), sumCompare());
      } else {
        // if the sum of the two numbers from the two arrays is smaller than the smallest (top)
        // element of the heap, we can 'break' here. Since the arrays are sorted in the descending
        // order, we'll not be able to find a pair with a higher sum moving forward.
        if (nums1[i] + nums2[j] < minHeap.front().first + minHeap.front().second) {
          break;
        } else {  // else: we have a pair with a larger sum, remove top and insert this pair in
                  // the heap
          pop_heap(minHeap.begin(), minHeap.end(), sumCompare());
          minHeap.pop_back();
          minHeap.push_back(make_pair(nums1[i], nums2[j]));
          push_heap(minHeap.begin(), minHeap.end(), sumCompare());
        }
      }
    }
  }
  return minHeap;
}


Time complexity #
Since, at most, we’ll be going through all the elements of both arrays and we will add/remove one element in the heap in each step, the time complexity of the above algorithm will be O(N∗M∗logK) where ‘N’ and ‘M’ are the total number of elements in both arrays, respectively.

If we assume that both arrays have at least ‘K’ elements then the time complexity can be simplified to O(K^2logK), because we are not iterating more than ‘K’ elements in both arrays.

Space complexity #
The space complexity will be O(K) because, at any time, our Min Heap will be storing ‘K’ largest pairs.
