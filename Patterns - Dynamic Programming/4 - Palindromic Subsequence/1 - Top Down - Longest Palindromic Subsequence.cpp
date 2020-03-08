public int findLPSLength(String st) {
  Integer[][] dp = new Integer[st.length()][st.length()];
  return findLPSLengthRecursive(dp, st, 0, st.length()-1);
}

private int findLPSLengthRecursive(Integer[][] dp, String st, int startIndex, int endIndex) {
  if(startIndex > endIndex)
    return 0;

  // every sequence with one element is a palindrome of length 1
  if(startIndex == endIndex)
    return 1;

  if(dp[startIndex][endIndex] == null) {
    // case 1: elements at the beginning and the end are the same
    if(st.charAt(startIndex) == st.charAt(endIndex)) {
      dp[startIndex][endIndex] = 2 + findLPSLengthRecursive(dp, st, startIndex+1, endIndex-1);
    } else {
      // case 2: skip one element either from the beginning or the end
      int c1 =  findLPSLengthRecursive(dp, st, startIndex+1, endIndex);
      int c2 =  findLPSLengthRecursive(dp, st, startIndex, endIndex-1);
      dp[startIndex][endIndex] = Math.max(c1, c2);
    }
  }

  return dp[startIndex][endIndex];
}
