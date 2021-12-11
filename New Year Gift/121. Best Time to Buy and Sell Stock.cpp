class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return -1;
        int minimum = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minimum) {
                minimum = prices[i];
            } else if (prices[i] - minimum > maxProfit) {
                maxProfit = prices[i] - minimum;
            }
        }
        
        return maxProfit;
    }
};