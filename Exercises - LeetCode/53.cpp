class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp(nums.size(),0);
        int maximum = nums[0];
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            maximum = max(maximum,dp[i]);
        }
        return maximum;

    }
};
