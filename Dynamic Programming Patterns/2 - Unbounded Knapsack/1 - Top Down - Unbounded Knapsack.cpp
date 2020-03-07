public int solveKnapsack(int[] profits, int[] weights, int capacity) {
  Integer[][] dp = new Integer[profits.length][capacity + 1];
  return this.knapsackRecursive(dp, profits, weights, capacity, 0);
}

private int knapsackRecursive(Integer[][] dp, int[] profits, int[] weights, int capacity,
    int currentIndex) {

  // base checks
  if (capacity <= 0 || profits.length == 0 || weights.length != profits.length ||
      currentIndex >= profits.length)
    return 0;

  // check if we have not already processed a similar sub-problem
  if(dp[currentIndex][capacity] == null) {
    // recursive call after choosing the items at the currentIndex, note that we recursive call on all
    // items as we did not increment currentIndex
    int profit1 = 0;
    if( weights[currentIndex] <= capacity )
        profit1 = profits[currentIndex] + knapsackRecursive(dp, profits, weights,
                capacity - weights[currentIndex], currentIndex);

    // recursive call after excluding the element at the currentIndex
    int profit2 = knapsackRecursive(dp, profits, weights, capacity, currentIndex + 1);

    dp[currentIndex][capacity] = Math.max(profit1, profit2);
  }

  return dp[currentIndex][capacity];
}
