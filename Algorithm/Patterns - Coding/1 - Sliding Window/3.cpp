using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int currentSum = 0;
    int minLength = numeric_limits<int>::max();
    int start = 0;
    for (int end = 0; end < arr.size(); end++) {
      currentSum += arr[end];

      while (currentSum >= S) {
        minLength = min(minLength, end - start + 1);
        currentSum -= arr[start];
        start++;
      }
    }
    return minLength != numeric_limits<int>::max() ? minLength : -1;
  }
};
