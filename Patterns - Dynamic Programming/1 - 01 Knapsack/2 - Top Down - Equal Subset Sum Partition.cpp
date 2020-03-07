public boolean canPartition(int[] num) {
  int sum = 0;
  for (int i = 0; i < num.length; i++)
    sum += num[i];

  if (sum % 2 != 0)
    return false;

  Boolean[][] dp = new Boolean[num.length][sum / 2 + 1];
  return this.canPartitionRecursive(dp, num, sum / 2, 0);
}

private boolean canPartitionRecursive(Boolean[][] dp, int[] num, int sum, int currentIndex) {
  if (sum == 0) return true;

  if (num.length == 0 || currentIndex >= num.length) return false;

  if (dp[currentIndex][sum] == null) {
    if (num[currentIndex] <= sum) {
      if (canPartitionRecursive(dp, num, sum - num[currentIndex], currentIndex + 1)) {
        dp[currentIndex][sum] = true;
        return true;
      }
    }

    dp[currentIndex][sum] = canPartitionRecursive(dp, num, sum, currentIndex + 1);
  }

  return dp[currentIndex][sum];
}
