Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.

Input: [2, 1, 5, 1, 3, 2], k=3
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].

Input: [2, 3, 4, 1, 5], k=2
Output: 7
Explanation: Subarray with maximum sum is [3, 4].

int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    // TODO: Write your code here
    int currentSum = 0;
    int windowStart = 0;
    for(int endWindow=0; endWindow<arr.size(); endWindow++){
      //sumo ultimo
      currentSum += arr[endWindow];
      if(endWindow >= k-1){
        //calculo
        if(currentSum>maxSum) maxSum = currentSum;
        //resto primero
        currentSum -= arr[windowStart];
        //muevo
        windowStart++;
      }
    }
    return maxSum;
  }

  Time Complexity #
  The time complexity of the above algorithm will be O(N).

  Space Complexity #
  The algorithm runs in constant space O(1).
