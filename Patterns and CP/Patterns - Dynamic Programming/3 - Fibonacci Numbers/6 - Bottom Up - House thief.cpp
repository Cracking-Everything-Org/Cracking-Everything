public int findMaxSteal(int[] wealth) {
  if(wealth.length == 0) return 0;
  int dp[] = new int[wealth.length+1]; // '+1' to handle the zero house
  dp[0] = 0; // if there are no houses, the thief can't steal anything
  dp[1] = wealth[0]; // only one house, so the thief have to steal from it

  // please note that dp[] has one extra element to handle zero house
  for(int i=1; i < wealth.length; i++)
    dp[i+1] = Math.max(wealth[i] + dp[i-1], dp[i]);

  return dp[wealth.length];
}
