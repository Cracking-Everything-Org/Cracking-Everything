public int findMSIS(int[] nums) {
  int[] dp = new int[nums.length];
  dp[0] = nums[0];

  int maxSum = nums[0];
  for (int i=1; i<nums.length; i++) {
    dp[i] = nums[i];
    for (int j=0; j<i; j++) {
      if (nums[i] > nums[j] && dp[i] < dp[j] + nums[i])
        dp[i] = dp[j] + nums[i];
    }
    maxSum = Math.max(maxSum, dp[i]);
  }

  return maxSum;
}
