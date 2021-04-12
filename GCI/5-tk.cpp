class TopKFrequentNumbers {
 struct compare {
   bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
     return a.second > b.second; 
   }
 };

 public:
  static vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) {
    vector<int> topNumbers;
    unordered_map<int, int> frequency;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;
    for (int i = 0; i < nums.size(); i++) {
      frequency[nums[i]]++;
    }
    for (auto entry : frequency) {
      minHeap.push(entry);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }
    while (!minHeap.empty()) {
      topNumbers.push_back(minHeap.top().first);
      minHeap.pop();
    }
    return topNumbers;
  }
};