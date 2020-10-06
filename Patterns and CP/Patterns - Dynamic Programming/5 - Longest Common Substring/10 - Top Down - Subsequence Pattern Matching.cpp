public int findSPMCount(String str, String pat) {
  Integer[][] dp = new Integer[str.length()][pat.length()];
  return findSPMCountRecursive(dp, str, pat, 0, 0);
}

private int findSPMCountRecursive(Integer[][] dp, String str, String pat, int strIndex, int patIndex) {

  // if we have reached the end of the pattern
  if(patIndex == pat.length())
    return 1;

  // if we have reached the end of the string but pattern has still some characters left
  if(strIndex == str.length())
    return 0;

  if(dp[strIndex][patIndex] == null) {
    int c1 = 0;
    if(str.charAt(strIndex) == pat.charAt(patIndex))
      c1 = findSPMCountRecursive(dp, str, pat, strIndex+1, patIndex+1);
    int c2 = findSPMCountRecursive(dp, str, pat, strIndex+1, patIndex);
    dp[strIndex][patIndex] = c1 + c2;
  }

  return dp[strIndex][patIndex];
}
