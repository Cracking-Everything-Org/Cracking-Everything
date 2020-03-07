public int canPartition(int[] num) {
  int sum = 0;
  for (int i = 0; i < num.length; i++)
    sum += num[i];

  int n = num.length;
  boolean[] dp = new boolean[sum/2 + 1];
  dp[0] = true;
  // with only one number, we can form a subset only when the required sum is equal to that number
  for(int s = 1; s <= sum/2 ; s++) {
    dp[s] = (num[0] == s ? true : false);
  }

  // process all subsets for all sums
  for(int i=1; i < num.length; i++) {
    for(int s=sum/2 ; s >= 1; s--) {
      if (s >= num[i]) {
        // else include the number and see if we can find a subset to get the remaining sum
        dp[s] = dp[s-num[i]];
      }
    }
  }

  int sum1 = 0;
  // Find the largest index in the last row which is true
  for (int i = sum / 2; i >= 0; i--) {
    if (dp[i] == true) {
        sum1 = i;
        break;
    }
  }

  int sum2 = sum - sum1;
  return Math.abs(sum2-sum1);
}

The above solution has time and space complexity of O(N*S), where ‘N’ represents total numbers and ‘S’ is the total sum of all the numbers.
