class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, 0);
        return countChangeRecursive(coins, amount, memo);
    }

    int countChangeRecursive(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        if (memo[amount] != 0) {
            return memo[amount];
        }
        int min = INT_MAX;
        for (int coin : coins) {
            int rest = countChangeRecursive(coins, amount - coin, memo);
            if (rest >= 0 && rest < min) {
                min = 1 + rest;
            }
        }
        memo[amount] = min == INT_MAX ? -1 : min;
        return memo[amount];
    }
};
