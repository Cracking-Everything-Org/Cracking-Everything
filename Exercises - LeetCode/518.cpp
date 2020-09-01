class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount <= 0) {
            return 1;
        }
        if (coins.size() <= 0) {
            return 0;
        }
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return getChange(amount, coins, 0, memo);
    }

    int getChange(int amount, vector<int>& coins, int index, vector<vector<int>>& memo) {
        if (amount < 0) {
            return 0;
        }
        if (amount == 0) {
            return 1;
        }
        if (memo[index][amount] != -1) {
            return memo[index][amount];
        }
        int combinations = 0;
        for (int i = index; i < coins.size(); i++) {
             combinations += getChange(amount - coins[i], coins, i, memo);
        }
        memo[index][amount] = combinations;
        return memo[index][amount];
    }
};
