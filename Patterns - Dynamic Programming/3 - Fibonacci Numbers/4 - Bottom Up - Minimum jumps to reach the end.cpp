public int countMinJumps(int[] jumps) {
  int[] dp = new int[jumps.length];

  //initialize with infinity, except the first index which should be zero as we start from there
  for(int i=1; i<jumps.length; i++)
    dp[i] = Integer.MAX_VALUE;

  for(int start=0; start < jumps.length-1; start++) {
    for(int end=start+1; end <= start+jumps[start] && end < jumps.length; end++)
      dp[end] = Math.min(dp[end], dp[start]+1);
  }

  return dp[jumps.length-1];
}
