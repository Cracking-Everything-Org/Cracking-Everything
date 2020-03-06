Given a set of positive numbers, partition the set into two subsets with minimum difference between their subset sums.

Example 1: #
Input: {1, 2, 3, 9}
Output: 3
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of numbers is '3'. Following are the two subsets: {1, 2, 3} & {9}.

Example 2: #
Input: {1, 2, 7, 1, 5}
Output: 0
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of number is '0'. Following are the two subsets: {1, 2, 5} & {7, 1}.

Example 3: #
Input: {1, 3, 100, 4}
Output: 92
Explanation: We can partition the given set into two subsets where minimum absolute difference
between the sum of numbers is '92'. Here are the two subsets: {1, 3, 4} & {100}.


int canPartition(const vector<int> &num) {
  int sum = 0;
  for (int i = 0; i < num.size(); i++) {
    sum += num[i];
  }

  int n = num.size();
  vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, false));

  // populate the sum=0 columns, as we can always form '0' sum with an empty set
  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }

  // with only one number, we can form a subset only when the sum is equal to that number
  for (int s = 0; s <= sum / 2; s++) {
    dp[0][s] = (num[0] == s ? true : false);
  }

  // process all subsets for all sums
  for (int i = 1; i < num.size(); i++) {
    for (int s = 1; s <= sum / 2; s++) {
      // if we can get the sum 's' without the number at index 'i'
      if (dp[i - 1][s]) {
        dp[i][s] = dp[i - 1][s];
      } else if (s >= num[i]) {
        // else include the number and see if we can find a subset to get the remaining sum
        dp[i][s] = dp[i - 1][s - num[i]];
      }
    }
  }

  int sum1 = 0;
  // Find the largest index in the last row which is true
  for (int i = sum / 2; i >= 0; i--) {
    if (dp[n - 1][i] == true) {
      sum1 = i;
      break;
    }
  }

  int sum2 = sum - sum1;
  return abs(sum2 - sum1);
}

Time and Space complexity #
The above solution has the time and space complexity of O(N*S), where ‘N’ represents total numbers and ‘S’ is the total sum of all the numbers.
