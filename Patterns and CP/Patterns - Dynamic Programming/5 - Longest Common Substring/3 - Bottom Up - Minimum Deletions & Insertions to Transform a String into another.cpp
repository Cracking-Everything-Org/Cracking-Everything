public void findMDI(String s1, String s2) {
  int c1 = findLCSLength(s1, s2);
  System.out.println("Minimum deletions needed: " + (s1.length() - c1));
  System.out.println("Minimum insertions needed: " + (s2.length() - c1));
}

private int findLCSLength(String s1, String s2) {
  int[][] dp = new int[s1.length()+1][s2.length()+1];
  int maxLength = 0;
  for(int i=1; i <= s1.length(); i++) {
    for(int j=1; j <= s2.length(); j++) {
      if(s1.charAt(i-1) == s2.charAt(j-1))
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);

      maxLength = Math.max(maxLength, dp[i][j]);
    }
  }
  return maxLength;
}
