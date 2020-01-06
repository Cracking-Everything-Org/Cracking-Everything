Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted

Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted

Input: [1, 2, 3]
Output: 0
Explanation: The array is already sorted

Input: [3, 2, 1]
Output: 3
Explanation: The whole array needs to be sorted.

int sort(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    // find the first number out of sorting order from the beginning
    while (low < arr.size() - 1 && arr[low] <= arr[low + 1]) {
      low++;
    }

    if (low == arr.size() - 1) {  // if the array is sorted
      return 0;
    }

    // find the first number out of sorting order from the end
    while (high > 0 && arr[high] >= arr[high - 1]) {
      high--;
    }

    // find the maximum and minimum of the subarray
    int subarrayMax = numeric_limits<int>::min(), subarrayMin = numeric_limits<int>::max();
    for (int k = low; k <= high; k++) {
      subarrayMax = max(subarrayMax, arr[k]);
      subarrayMin = min(subarrayMin, arr[k]);
    }

    // extend the subarray to include any number which is bigger than the minimum of the subarray
    while (low > 0 && arr[low - 1] > subarrayMin) {
      low--;
    }
    // extend the subarray to include any number which is smaller than the maximum of the subarray
    while (high < arr.size() - 1 && arr[high + 1] < subarrayMax) {
      high++;
    }

    return high - low + 1;
  }

  Time complexity #
  The time complexity of the above algorithm will be O(N).

  Space complexity #
  The algorithm runs in constant space O(1).
