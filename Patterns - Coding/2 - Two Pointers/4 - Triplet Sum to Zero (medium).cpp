Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.

Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.

vector<vector<int>> searchTriplets(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> triplets;
    for (int i = 0; i < arr.size() - 2; i++) {
      if (i > 0 && arr[i] == arr[i - 1]) { // skip same element to avoid duplicate triplets
        continue;
      }
      searchPair(arr, -arr[i], i + 1, triplets);
    }

    return triplets;
  }

  void searchPair(const vector<int> &arr, int targetSum, int left,
                           vector<vector<int>> &triplets) {
      int right = arr.size() - 1;
      while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == targetSum) { // found the pair
          triplets.push_back({-targetSum, arr[left], arr[right]});
          left++;
          right--;
          while (left < right && arr[left] == arr[left - 1]) {
            left++; // skip same element to avoid duplicate triplets
          }
          while (left < right && arr[right] == arr[right + 1]) {
            right--; // skip same element to avoid duplicate triplets
          }
        } else if (targetSum > currentSum) {
          left++; // we need a pair with a bigger sum
        } else {
          right--; // we need a pair with a smaller sum
        }
      }
    }

Time complexity #
Sorting the array will take O(N * logN). The searchPair() function will take O(N). As we are calling searchPair() for every number in the input array, this means that overall searchTriplets() will take O(N * logN + N^2), which is asymptotically equivalent to O(N^2).

Space complexity #
Ignoring the space required for the output array, the space complexity of the above algorithm will be O(N) which is required for sorting.
