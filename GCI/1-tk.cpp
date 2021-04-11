class KLargestNumbers {
 public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < nums.size(); i++) {
      minHeap.push(nums[i]);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    while (!minHeap.empty()) {
      result.push_back(minHeap.top());
      minHeap.pop();
    }

    return result;
  }
};