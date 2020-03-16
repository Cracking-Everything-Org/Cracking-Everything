class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int> dp;
        dp[0] = cost[0];
        dp[1] = cost[1];
        int n = cost.size()-1;
        for (int i = 2; i <= n; i++) {
           dp[i] = min(dp[i-1], dp[i-2]) + (i > n ? 0 : cost[i]);
        }

        return min(dp[n], dp[n-1]);
    }
};
