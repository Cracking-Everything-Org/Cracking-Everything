class AverageOfSubarrayOfSizeK {
 public:
  static vector<double> findAverages(int K, const vector<int>& arr) {
    vector<double> result(arr.size() - K + 1);
    for (int i = 0; i <= arr.size() - K; i++) {
      // find sum of next 'K' elements
      double sum = 0;
      for (int j = i; j < i + K; j++) {
        sum += arr[j];
      }
      result[i] = sum / K;  // calculate average
    }

    return result;
  }
};