public int canPartition(int[] num) {
  int sum = 0;
  for (int i = 0; i < num.length; i++)
    sum += num[i];

  Integer[][] dp = new Integer[num.length][sum + 1];
  return this.canPartitionRecursive(dp, num, 0, 0, 0);
}

private int canPartitionRecursive(Integer[][] dp, int[] num, int currentIndex, int sum1, int sum2) {
  // base check
  if(currentIndex == num.length)
    return Math.abs(sum1 - sum2);

  // check if we have not already processed similar problem
  if(dp[currentIndex][sum1] == null) {
    // recursive call after including the number at the currentIndex in the first set
    int diff1 = canPartitionRecursive(dp, num, currentIndex + 1, sum1 + num[currentIndex], sum2);

    // recursive call after including the number at the currentIndex in the second set
    int diff2 = canPartitionRecursive(dp, num, currentIndex + 1, sum1, sum2 + num[currentIndex]);

    dp[currentIndex][sum1] = Math.min(diff1, diff2);
  }

  return dp[currentIndex][sum1];
}
