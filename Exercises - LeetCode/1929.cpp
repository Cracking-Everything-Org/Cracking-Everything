class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        
        if (!size) return nums;
        
        for (int i = 0; i < size; i++) {
            nums.push_back(nums[i]);
        }
        
        return nums;
    }
};