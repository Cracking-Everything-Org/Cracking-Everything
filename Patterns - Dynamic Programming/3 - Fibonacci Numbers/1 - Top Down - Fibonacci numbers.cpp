public int CalculateFibonacci(int n) {
  int dp[] = new int[n + 1];
  return CalculateFibonacciRecursive(dp, n);
}

public int CalculateFibonacciRecursive(int[] dp, int n) {
  if (n < 2)
    return n;
  if (dp[n] == 0)
    dp[n] = CalculateFibonacciRecursive(dp, n - 1) + CalculateFibonacciRecursive(dp, n - 2);
  return dp[n];
}
