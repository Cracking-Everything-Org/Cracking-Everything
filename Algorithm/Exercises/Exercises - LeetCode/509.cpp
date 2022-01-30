class Solution {
public:
    int fib(int N) {
        vector<int> dp(N+1, -1);
        if (N < 2) return N;
        return findFib(N, dp);
    }

    int findFib(int N, vector<int>& dp) {
        if (N < 2) return N;
        dp[N] = findFib(N-1, dp) + findFib(N-2, dp);
        return dp[N];
    }
};
