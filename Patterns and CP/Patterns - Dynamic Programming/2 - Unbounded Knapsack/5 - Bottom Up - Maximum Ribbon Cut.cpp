public int countRibbonPieces(int[] ribbonLengths, int total)
{
  int n = ribbonLengths.length;
  int[][] dp = new int[n][total + 1];

  for(int i=0; i < n; i++)
    for(int j=0; j <= total; j++)
      dp[i][j] = Integer.MIN_VALUE;

  // populate the total=0 columns, as we don't need any ribbon to make zero total
  for(int i=0; i < n; i++)
    dp[i][0] = 0;

  for(int i=0; i < n; i++) {
    for(int t=1; t <= total; t++) {
      if(i > 0) //exclude the ribbon
        dp[i][t] = dp[i-1][t];
      // include the ribbon and check if the remaining length can be cut into available lengths
      if(t >= ribbonLengths[i] && dp[i][t-ribbonLengths[i]] != Integer.MIN_VALUE)
        dp[i][t] = Math.max(dp[i][t], dp[i][t-ribbonLengths[i]]+1);
    }
  }

  // total combinations will be at the bottom-right corner, return '-1' if cutting is not possible
  return (dp[n-1][total] == Integer.MIN_VALUE ? -1 : dp[n-1][total]);
}
