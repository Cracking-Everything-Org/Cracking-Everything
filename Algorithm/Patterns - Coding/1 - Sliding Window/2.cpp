using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    int currentSum = 0;
    int start = 0;
    for (int end = 0; end < arr.size(); end++) {
      currentSum += arr[end];
      
      if (end - start + 1 >= k) {
        maxSum = max(maxSum, currentSum);
        currentSum -= arr[start];
        start++;
      }
    }
    return maxSum;
  }
};
