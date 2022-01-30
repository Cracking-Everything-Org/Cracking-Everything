class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        memo[0] = nums[0];
        int maximum = memo[0];

        for (int i = 1; i < nums.size(); i++) {
            memo[i] = max(nums[i], memo[i - 1] + nums[i]);
            maximum = maximum < memo[i] ? memo[i] : maximum;
        }

        return maximum;
    }
};
