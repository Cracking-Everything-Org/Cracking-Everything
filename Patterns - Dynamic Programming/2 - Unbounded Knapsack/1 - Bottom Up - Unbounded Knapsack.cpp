public int solveKnapsack(int[] profits, int[] weights, int capacity) {
  // base checks
  if (capacity <= 0 || profits.length == 0 || weights.length != profits.length)
    return 0;

  int n = profits.length;
  int[][] dp = new int[n][capacity + 1];

  // populate the capacity=0 columns
  for(int i=0; i < n; i++)
    dp[i][0] = 0;

  // process all sub-arrays for all capacities
  for(int i=0; i < n; i++) {
    for(int c=1; c <= capacity; c++) {
      int profit1=0, profit2=0;
      if(weights[i] <= c)
        profit1 = profits[i] + dp[i][c-weights[i]];
      if( i > 0 )
        profit2 = dp[i-1][c];
      dp[i][c] = profit1 > profit2 ? profit1 : profit2;
    }
  }

  // maximum profit will be in the bottom-right corner.
  return dp[n-1][capacity];
}
