Given a set of positive numbers, find if we can partition it into two subsets such that the sum of elements in both subsets is equal.

Example 1:

Input: {1, 2, 3, 4}
Output: True
Explanation: The given set can be partitioned into two subsets with equal sum: {1, 4} & {2, 3}
Example 2:

Input: {1, 1, 3, 4, 7}
Output: True
Explanation: The given set can be partitioned into two subsets with equal sum: {1, 3, 4} & {1, 7}
Example 3:

Input: {2, 3, 4, 6}
Output: False
Explanation: The given set cannot be partitioned into two subsets with equal sum.


public:
bool canPartition(const vector<int> &num) {
  int sum = 0;
  for (int i = 0; i < num.size(); i++) {
    sum += num[i];
  }

  // if 'sum' is a an odd number, we can't have two subsets with equal sum
  if (sum % 2 != 0) {
    return false;
  }

  vector<vector<int>> dp(num.size(), vector<int>(sum / 2 + 1, -1));
  return this->canPartitionRecursive(dp, num, sum / 2, 0);
}

private:
bool canPartitionRecursive(vector<vector<int>> &dp, const vector<int> &num, int sum,
                           int currentIndex) {
  // base check
  if (sum == 0) {
    return true;
  }

  if (num.empty() || currentIndex >= num.size()) {
    return false;
  }

  // if we have not already processed a similar problem
  if (dp[currentIndex][sum] == -1) {
    // recursive call after choosing the number at the currentIndex
    // if the number at currentIndex exceeds the sum, we shouldn't process this
    if (num[currentIndex] <= sum) {
      if (canPartitionRecursive(dp, num, sum - num[currentIndex], currentIndex + 1)) {
        dp[currentIndex][sum] = 1;
        return true;
      }
    }

    // recursive call after excluding the number at the currentIndex
    dp[currentIndex][sum] = canPartitionRecursive(dp, num, sum, currentIndex + 1) ? 1 : 0;
  }

  return dp[currentIndex][sum] == 1 ? true : false;
}


Time and Space complexity #
The above algorithm has the time and space complexity of O(N*S), where ‘N’ represents total numbers and ‘S’ is the total sum of all the numbers.
