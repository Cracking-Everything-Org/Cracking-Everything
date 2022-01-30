int countSubsets(int[] num, int sum) {
  //TODO: Write - Your - Code
  int n = num.length;
  int[] dp = new int[sum+1];

  for(int i=0; i < n; i++)
    dp[i]= 1;

  for(int s=1; s <= sum ; s++) {
    dp[s] = (num[0] == s ? 1 : 0);
  }

  for(int i=1; i<n; i++){
    for(int j=sum; j>=1; j--){
      if(j >= num[i])
        dp[j] += dp[j-num[i]];
    }
  }

  return dp[sum];
}
