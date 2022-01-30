Given a set of positive numbers, determine if a subset exists whose sum is equal to a given number ‘S’.

Example 1: #
Input: {1, 2, 3, 7}, S=6
Output: True
The given set has a subset whose sum is '6': {1, 2, 3}

Example 2: #
Input: {1, 2, 7, 1, 5}, S=10
Output: True
The given set has a subset whose sum is '10': {1, 2, 7}

Example 3: #
Input: {1, 3, 4, 8}, S=6
Output: False
The given set does not have any subset whose sum is equal to '6'.


bool canPartition(const vector<int> &num, int sum) {
  int n = num.size();
  vector<bool> dp(sum+1);

  // con cuantos hago 0?
  dp[0] = true;

  // con solo 1
  for (int s = 1; s <= sum; s++) {
    dp[s] = (s == num[0] ? true : false);
  }

  // con el resto
  for (int i = 1; i < n; i++) {
    for (int c = sum; c >= 0; c--) {
      if (!dp[c] && c >= num[i]) {
        dp[c] = dp[c - num[i]];
      }
    }
  }

  return dp[sum];
}


Space complexity #
O(c)
