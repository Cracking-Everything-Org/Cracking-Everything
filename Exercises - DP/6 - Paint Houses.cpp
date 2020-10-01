/*
Paint Houses

/* RECURSIVE */
int minCostMemo(vector<vector<int>> costs, int i, int color, vector<vector<int>> cache) {
    if (i == costs.size()) {
      return 0;
    }
    if (costs[i][color] != -1) {
      return cache[i][color];
    }
    if (color == 0) {
      int costBlue = minCostMemo(costs, i + 1, 1, cache);
      int costGreen = minCostMemo(costs, i + 1, 2, cache);
      return cache[i][color] = cost[i][0] + min(costBlue, costGreen);
    } else if (color == 1) {
      int costRed = minCostMemo(costs, i + 1, 0, cache);
      int costGreen = minCostMemo(costs, i + 1, 2, cache);
      return cache[i][color] = cost[i][0] + min(costRed, costGreen);
    } else {
      int costRed = minCostMemo(costs, i + 1, 0, cache);
      int costBlue = minCostMemo(costs, i + 1, 1, cache);
      return cache[i][color] = cost[i][0] + min(costRed, costBlue);
    }
    return 0;
}

int minCost(vector<vector<int>> cost) {
  vector<vector<int>> cache(cost.size(), vector<int>(cost[0].size(), -1));
  int costRed = minCostMemo(costs, 0, 0, cache);
  int costBlue = minCostMemo(costs, 0, 1, cache);
  int costGreen = minCostMemo(costs, 0, 2, cache);
  return min(costRed, min(costGreen, costBlue));
}
