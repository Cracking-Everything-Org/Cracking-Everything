class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int profit = 0;
        int index = 0;

        while(index < prices.size() -1){
            while(index < prices.size() -1 && prices[index] >= prices[index+1]){
                index++;
            }
            profit -= prices[index];
            while(index < prices.size() -1 && prices[index] <= prices[index+1]){
                index++;
            }
            profit += prices[index];
        }
        return profit;
    }
};
