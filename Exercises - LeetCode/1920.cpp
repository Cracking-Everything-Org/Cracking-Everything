class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int size = nums.size();
        if (!size) return nums;
        
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
            ans.push_back(nums[nums[i]]);

        return ans;
    }
};