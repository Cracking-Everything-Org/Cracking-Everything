class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int globalMax = 0;
    int localMax = 0;
    int start = 0;
    for (int end = 0; end < arr.size(); end++) {
      localMax += arr[end];
      if (start + end - 1 >= k) {
        globalMax = globalMax > localMax ? globalMax : localMax;
        localMax -= arr[end];
        start++;
      }
    }
    return globalMax;
  }
};