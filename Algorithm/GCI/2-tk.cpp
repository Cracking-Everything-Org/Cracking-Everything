class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(const vector<int> &nums, int k) {
    priority_queue<int> maxHeap;
    for (int i = 0; i < nums.size(); i++) {
      maxHeap.push(nums[i]);
      if (maxHeap.size() > k) {
        maxHeap.pop();
      }
    }
    return maxHeap.top();
  }
};