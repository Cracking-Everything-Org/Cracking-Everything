class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int,int> dp;
        return climb(0, n, dp);
    }

    int climb(int pos, int n, unordered_map<int,int>& dp) {
        if (dp[pos] > 0) return dp[pos];
        if (pos > n) return 0;
        if (pos == n) return 1;
        dp[pos] = climb(pos + 1, n, dp) + climb(pos + 2, n , dp);
        return dp[pos];
    }
};
