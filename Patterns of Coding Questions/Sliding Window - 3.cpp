Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.

Input: [2, 1, 5, 2, 3, 2], S=7
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].

Input: [2, 1, 5, 2, 8], S=7
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].

Input: [3, 4, 1, 1, 6], S=8
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] or [1, 1, 6].


int findMinSubArray(int S, const vector<int>& arr) {
    // TODO: Write your code here
    int subarraySize = numeric_limits<int>::max();
    int windowSum = 0;
    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++ ){
      // add the last element
      windowSum += arr[windowEnd];
      // shrink the window as small as possible until the 'windowSum' is smaller than 'S'
      while(windowSum >= S){
        subarraySize = min(subarraySize, windowEnd - windowStart + 1);
        windowSum -= arr[windowStart];
        windowStart++;
      }
    }
    return subarraySize == numeric_limits<int>::max() ? 0 : subarraySize;
  }
