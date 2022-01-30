public int findLCSLength(String s1, String s2) {
  int maxLength = Math.min(s1.length(), s2.length());
  Integer[][][] dp = new Integer[s1.length()][s2.length()][maxLength];
  return findLCSLengthRecursive(dp, s1, s2, 0, 0, 0);
}

private int findLCSLengthRecursive(Integer[][][] dp, String s1, String s2, int i1, int i2, int count) {
  if(i1 == s1.length() || i2 == s2.length())
    return count;

  if(dp[i1][i2][count] == null) {
    int c1 = count;
    if(s1.charAt(i1) == s2.charAt(i2))
      c1 = findLCSLengthRecursive(dp, s1, s2, i1+1, i2+1, count+1);
    int c2 = findLCSLengthRecursive(dp, s1, s2, i1, i2+1, 0);
    int c3 = findLCSLengthRecursive(dp, s1, s2, i1+1, i2, 0);
    dp[i1][i2][count] = Math.max(c1, Math.max(c2, c3));
  }

  return dp[i1][i2][count];
}
