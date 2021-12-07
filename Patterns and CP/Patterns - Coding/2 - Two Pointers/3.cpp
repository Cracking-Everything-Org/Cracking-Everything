using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 2; i++) {
      if (i > 0 && arr[i] == arr[i - 1]) continue;
      twoSum(-arr[i], i + 1, arr.size() - 1, arr, triplets);
    }
    return triplets;
  }
  
 public: 
  static void twoSum(int target, int left, int right, vector<int>& arr, vector<vector<int>>& triplets) {
    while (left < right) {
      int sum = arr[left] + arr[right];
      if (sum == target) {
        triplets.push_back({-target, arr[left], arr[right]});
        left++;
        right--;
        while (left < right && arr[left] == arr[left - 1]) {
          left++;
        }
        while (left < right && arr[right] == arr[right + 1]) {
          right--;
        }
      } 
      else if (sum > target) {
        right--;
      } else {
        left++;
      }
    }
  }
};
  
