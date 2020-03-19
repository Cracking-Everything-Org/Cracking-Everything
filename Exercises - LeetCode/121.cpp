class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = INT_MAX;

        for (int i = 0 ; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else {
                profit = max(profit, prices[i] - buy);
            }
        }
        return profit;
    }
};
