public int countChange(int[] denominations, int total)
{
  Integer[][] dp = new Integer[denominations.length][total + 1];
  return this.countChangeRecursive(dp, denominations, total, 0);
}

private int countChangeRecursive(Integer[][] dp, int[] denominations, int total, int currentIndex)
{
  // base checks
  if (total == 0)
    return 1;

  if(denominations.length == 0 || currentIndex >= denominations.length)
    return 0;

  // if we have already processed a similar sub-problem, return the result from memory
  if(dp[currentIndex][total] != null)
    return dp[currentIndex][total];

  // recursive call after selecting the coin at the currentIndex
  // if the number at currentIndex exceeds the total, we shouldn't process this
  int sum1 = 0;
  if( denominations[currentIndex] <= total )
    sum1 = countChangeRecursive(dp, denominations, total - denominations[currentIndex], currentIndex);

  // recursive call after excluding the number at the currentIndex
  int sum2 = countChangeRecursive(dp, denominations, total, currentIndex + 1);

  dp[currentIndex][total] = sum1 + sum2;
  return dp[currentIndex][total];
}
