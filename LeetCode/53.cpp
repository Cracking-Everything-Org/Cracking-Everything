class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_current = 0;
        int max_global = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            max_current = max(nums[i], max_current + nums[i]);
            max_global = max(max_global, max_current);
        }
        return max_global;
    }
}; 
