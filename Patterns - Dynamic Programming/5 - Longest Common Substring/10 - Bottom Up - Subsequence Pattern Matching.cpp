public int findSPMCount(String str, String pat) {
  // every empty pattern has one match
  if(pat.length() == 0)
    return 1;

  if(str.length() == 0 || pat.length() > str.length())
    return 0;

  // dp[strIndex][patIndex] will be storing the count of SPM up to str[0..strIndex-1][0..patIndex-1]
  int[][] dp = new int[str.length()+1][pat.length()+1];

  // for the empty pattern, we have one matching
  for(int i=0; i<=str.length(); i++)
    dp[i][0] = 1;

  for(int strIndex=1; strIndex<=str.length(); strIndex++) {
    for(int patIndex=1; patIndex<=pat.length(); patIndex++) {
      if(str.charAt(strIndex-1) == pat.charAt(patIndex-1))
        dp[strIndex][patIndex] = dp[strIndex-1][patIndex-1];
      dp[strIndex][patIndex] += dp[strIndex-1][patIndex];
    }
  }

  return dp[str.length()][pat.length()];
}
