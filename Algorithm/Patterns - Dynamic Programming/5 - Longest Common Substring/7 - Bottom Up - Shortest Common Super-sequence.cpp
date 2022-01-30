public int findSCSLength(String s1, String s2) {
  int[][] dp = new int[s1.length()+1][s2.length()+1];

  // if one of the strings is of zero length, SCS would be equal to the length of the other string
  for(int i=0; i<=s1.length(); i++)
    dp[i][0] = i;
  for(int j=0; j<=s2.length(); j++)
    dp[0][j] = j;

  for(int i=1; i <= s1.length(); i++) {
    for(int j=1; j <= s2.length(); j++) {
      if(s1.charAt(i-1) == s2.charAt(j-1))
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = 1 + Math.min(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[s1.length()][s2.length()];
}
