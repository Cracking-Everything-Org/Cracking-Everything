class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> profit(nums.size() + 1, -1);
        return houseRob(nums, 0, profit);
    }

    int houseRob(vector<int>& nums, int pos, vector<int> &dp) {
        if (pos >= nums.size()) return 0;
        if (dp[pos] == -1) {
            int including = nums[pos] + houseRob(nums, pos + 2, dp);
            int excluding = houseRob(nums, pos + 1, dp);

            dp[pos] = max(including, excluding);
        }
        return dp[pos];
    }
};
