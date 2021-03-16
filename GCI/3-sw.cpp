class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int minLength = INT_MAX;
    int sum = 0;
    int start = 0;
    for (int end = 0; end < arr.size(); end++) {
      sum += arr[end];
      
      while(sum >= S) {
        minLength = min(minLength, end - start + 1);
        sum -= arr[start];
        start++;
      }
    }

    return minLength == INT_MAX ? 0 : minLength;
  }
};