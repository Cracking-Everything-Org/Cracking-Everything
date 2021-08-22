class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        if (!nums.size()) return nums;
        
        vector<int> shuffledList;
        
        for (int i = 0; i < n; i++) {
            shuffledList.push_back(nums[i]);
            shuffledList.push_back(nums[n + i]);
        }
        
        return shuffledList;
    }
};