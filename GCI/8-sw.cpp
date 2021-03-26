using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int maxLength = 0;
    int start = 0;
    int zeroCount = 0;
    for (int end = 0; end < arr.size(); end++) {
      if (arr[end] == 0) {
        zeroCount++;
      }
      while (zeroCount > k) {
        if (arr[start] == 0) {
          zeroCount--;
        }
        start++;
      }
       maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }
};