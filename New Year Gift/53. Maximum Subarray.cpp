class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0];
        int maximum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currentMax = max(currentMax + nums[i], nums[i]);
            maximum = max(maximum, currentMax);
        }
        return maximum;
    }
};