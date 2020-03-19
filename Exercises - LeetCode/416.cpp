class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) return false;
        sum /= 2;

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return canPart(nums, 0, sum, dp);
    }

    bool canPart(vector<int>& nums, int position, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (position == nums.size()) return false;

        if (dp[position][sum] == -1) {
            //include
            if (nums[position] <= sum) {
                if (canPart(nums, position + 1, sum - nums[position], dp)) {
                    dp[position][sum] = 1;
                    return true;
                }
            }
            //exclude
            dp[position][sum] = canPart(nums, position + 1, sum, dp) ? 1 : 0;
        }

        return dp[position][sum];
    }

};
