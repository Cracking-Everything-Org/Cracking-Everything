Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.

Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
Output: 6
Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.

Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.

int findLength(const vector<int>& arr, int k) {
    int maxLength = 0;
    // TODO: Write your code here
    int windowStart = 0;
    int currentZeros = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      int rightInt = arr[windowEnd];
      if (rightInt == 0){
        currentZeros++;
        while (currentZeros > k){
          int leftInt = arr[windowStart];
          if (leftInt == 0) currentZeros--;
          windowStart++;
        }
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
  }

Time Complexity #
The time complexity of the above algorithm will be O(N) where ‘N’ is the count of numbers in the input array.

Space Complexity #
The algorithm runs in constant space O(1).
