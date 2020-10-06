public int findLRSLength(String str) {
  Integer[][] dp = new Integer[str.length()][str.length()];
  return findLRSLengthRecursive(dp, str, 0, 0);
}

private int findLRSLengthRecursive(Integer[][] dp, String str, int i1, int i2) {
  if(i1 == str.length() || i2 == str.length())
    return 0;

  if(dp[i1][i2] == null) {
    if(i1 != i2 && str.charAt(i1) == str.charAt(i2))
      dp[i1][i2] = 1 + findLRSLengthRecursive(dp, str, i1+1, i2+1);
    else {
      int c1 = findLRSLengthRecursive(dp, str, i1, i2+1);
      int c2 = findLRSLengthRecursive(dp, str, i1+1, i2);
      dp[i1][i2] = Math.max(c1, c2);
    }
  }

  return dp[i1][i2];
}
