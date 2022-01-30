public int findSCSLength(String s1, String s2) {
  Integer[][] dp = new Integer[s1.length()][s2.length()];
  return findSCSLengthRecursive(dp, s1, s2, 0, 0);
}

private int findSCSLengthRecursive(Integer[][] dp, String s1, String s2, int i1, int i2) {
  // if we have reached the end of a string, return the remaining length of the other string,
  // as in this case we have to take all of the remaining other string
  if(i1 == s1.length())
    return s2.length()-i2;
  if(i2 == s2.length())
    return s1.length()-i1;

  if(dp[i1][i2] == null) {
    if(s1.charAt(i1) == s2.charAt(i2))
      dp[i1][i2] = 1 + findSCSLengthRecursive(dp, s1, s2, i1+1, i2+1);
    else {
      int length1 = 1 + findSCSLengthRecursive(dp, s1, s2, i1, i2+1);
      int length2 = 1 + findSCSLengthRecursive(dp, s1, s2, i1+1, i2);
      dp[i1][i2] = Math.min(length1, length2);
    }
  }

  return dp[i1][i2];
}
