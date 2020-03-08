static int findLCSLength(String s1, String s2) {
  int[][] dp = new int[2][s2.length()+1];
  int maxLength = 0;
  for(int i=1; i <= s1.length(); i++) {
    for(int j=1; j <= s2.length(); j++) {
      dp[i%2][j] = 0;
      if(s1.charAt(i-1) == s2.charAt(j-1)) {
        dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
        maxLength = Math.max(maxLength, dp[i%2][j]);
      }
    }
  }
  return maxLength;
}
