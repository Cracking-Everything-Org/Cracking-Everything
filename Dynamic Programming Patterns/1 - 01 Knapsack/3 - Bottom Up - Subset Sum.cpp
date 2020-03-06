public boolean canPartition(int[] num, int sum) {
  int n = num.length;
  boolean[] dp = new boolean[sum + 1];

  for (int s = 1; s <= sum; s++) {
    dp[s] = (num[0] == s ? true : false);
  }

  // process all subsets for all sums
  for (int i = 1; i < num.length; i++) {
    for (int s = sum; s >= 1; s--) {
      // if we can get the sum 's' without the number at index 'i'
      if (s >= num[i]) {
        dp[s] = dp[s - num[i]];
      }
    }
  }

  // the bottom-right corner will have our answer.
  return dp[sum];
}

The above solution has time and space complexity of O(N*S), where ‘N’
