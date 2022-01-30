using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>


class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
    sort(arr.begin(), arr.end());
    int smallestDifference = numeric_limits<int>::max();
    for (int i = 0; i < arr.size() - 2; i++) {
      int left = i + 1, right = arr.size() - 1;
      while (left < right) {
        int targetDiff = targetSum - arr[i] - arr[left] - arr[right];
        
        if (targetDiff == 0) {
          return targetSum - targetDiff;
        }

        if (abs(targetDiff) < abs(smallestDifference) ||
              (abs(targetDiff) == abs(smallestDifference) && targetDiff > smallestDifference)) {
          smallestDifference = targetDiff;
        }

        if (targetDiff > 0) {
          left++;
        } else {
          right--;
        }
      }
    }
    return targetSum - smallestDifference;
  }
};

