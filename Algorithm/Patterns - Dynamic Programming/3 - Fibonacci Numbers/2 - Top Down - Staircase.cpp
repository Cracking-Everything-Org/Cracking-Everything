public int CountWays(int n) {
  int dp[] = new int[n+1];
  return CountWaysRecursive(dp, n);
}

public int CountWaysRecursive(int[] dp, int n) {
  if( n == 0)
    return 1; // base case, we don't need to take any step, so there is only one way

  if(n == 1)
    return 1; // we can take one step to reach the end, and that is the only way

  if(n == 2)
    return 2; // we can take one step twice or jump two steps to reach at the top

  if(dp[n] == 0) {
    // if we take 1 step, we are left with 'n-1' steps;
    int take1Step = CountWaysRecursive(dp, n-1);
    // similarly, if we took 2 steps, we are left with 'n-2' steps;
    int take2Step = CountWaysRecursive(dp, n-2);
    // if we took 3 steps, we are left with 'n-3' steps;
    int take3Step = CountWaysRecursive(dp, n-3);
    dp[n] = take1Step + take2Step + take3Step;
  }

  return dp[n];
}
