class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        if (total % k != 0) return false;
        vector<vector<int>> memo;
		memo.resize(16, vector<int>(nums.size(), -1));
        return findWays(nums, memo, 0, 0, total / k) == k;
    }

    int findWays(vector<int>& nums, vector<vector<int>>& memo, int index, int current, int target) {
        if (current == target) {
            return 1;
        }
        if (index == nums.size() || current > target) {
            return 0;
        }
        if (memo[current][index] != -1) {
            return memo[current][index];
        }
        int including = 0;
        if (current + nums[index] <= target) {
             including = findWays(nums, memo, index + 1, current + nums[index], target);
        }
        int excluding = findWays(nums, memo, index + 1, current, target);

        memo[current][index] = including + excluding;
        return including + excluding;
    }
};
