public int findLCSLength(String s1, String s2) {
  Integer[][] dp = new Integer[s1.length()][s2.length()];
  return findLCSLengthRecursive(dp, s1, s2, 0, 0);
}

private int findLCSLengthRecursive(Integer[][] dp, String s1, String s2, int i1, int i2) {
  if (i1 == s1.length() || i2 == s2.length())
    return 0;

  if (dp[i1][i2] == null) {
    if (s1.charAt(i1) == s2.charAt(i2))
      dp[i1][i2] = 1 + findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2 + 1);
    else {
      int c1 = findLCSLengthRecursive(dp, s1, s2, i1, i2 + 1);
      int c2 = findLCSLengthRecursive(dp, s1, s2, i1 + 1, i2);
      dp[i1][i2] = Math.max(c1, c2);
    }
  }

  return dp[i1][i2];
}
