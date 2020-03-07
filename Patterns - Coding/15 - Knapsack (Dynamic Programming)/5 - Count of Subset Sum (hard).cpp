Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.

Example 1: #
Input: {1, 1, 2, 3}, S=4
Output: 3
The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
Note that we have two similar sets {1, 3}, because we have two '1' in our input.

Example 2: #
Input: {1, 2, 7, 1, 5}, S=9
Output: 3
The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1, 5}

int countSubsets(const vector<int> &num, int sum) {
  int n = num.size();
  vector<int> dp(sum + 1);
  dp[0] = 1;

  // with only one number, we can form a subset only when the required sum is
  // equal to its value
  for (int s = 1; s <= sum; s++) {
    dp[s] = (num[0] == s ? 1 : 0);
  }

  // process all subsets for all sums
  for (int i = 1; i < num.size(); i++) {
    for (int s = sum; s >= 0; s--) {
      if (s >= num[i]) {
        dp[s] += dp[s - num[i]];
      }
    }
  }

  return dp[sum];
}

Time and Space complexity

O(S)
