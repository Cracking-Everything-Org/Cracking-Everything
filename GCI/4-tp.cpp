using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 3; i++) {
      while (i > 0 && i < arr.size() - 3 && arr[i] == arr[i - 1]) i++;
      searchPair(arr, -arr[i], i + 1, triplets);
    }
    return triplets;
  }

private:
  static void searchPair(const vector<int> &arr, int targetSum, int left, vector<vector<int>> &triplets) {
    int right = arr.size() - 1;
    while (left < right) {
      int currentSum = arr[left] + arr[right];
      if (currentSum == targetSum) {
        triplets.push_back({-targetSum, arr[left], arr[right]});
        left++;
        right--;
        while (left < right && arr[left] == arr[left - 1]) left++;
        while (left < right && arr[right] == arr[right + 1]) right--;
      } 
      else if (targetSum > currentSum) left++;
      else right--;
    }
  }
};
  