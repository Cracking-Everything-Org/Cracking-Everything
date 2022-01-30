class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> memo(N + 1, false);
        return divisor(N, memo);
    }

    bool divisor(int N, vector<bool>& memo) {
        bool result = false;
        if (memo[N]) {
            return memo[N];
        }
        for (int x = 1; !result && x <= N / 2; x++) {
            if (N % x == 0) {
                result = !divisor(N - x, memo);
            }
        }
        memo[N] = result;
        return memo[N];
    }

};
