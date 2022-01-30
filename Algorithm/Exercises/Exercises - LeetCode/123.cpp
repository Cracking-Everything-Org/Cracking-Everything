class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size(), min_l = INT_MAX, max_r = 0, res = 0;
      vector<int> left(n + 1), right(n + 1);
      for (auto i = 0; i < n; ++i) {
        auto price_l = prices[i], price_r = prices[n - i - 1];
        min_l = min(min_l, price_l);
        max_r = max(max_r, price_r);
        left[i + 1] = max(left[i], price_l - min_l);
        right[n - i - 1] = max(right[n - i], max_r - price_r);
      }
      for (auto i = 0; i <= n; ++i) res = max(res, left[i] + right[i]);
      return res;
    }
};
