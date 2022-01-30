class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.size() <= 0) {
            return ranges;
        }
        int start = nums[0];
        int end = nums[0];
        string currentRange;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) {
                end = nums[i];
            } else {
                if (start != end) {
                    currentRange = to_string(start) + "->" + to_string(end); 
                } else {
                    currentRange = to_string(start);
                }
                start = nums[i];
                end = nums[i];
                ranges.push_back(currentRange);
            }
        }
        
        if (start != end) {
            currentRange = to_string(start) + "->" + to_string(end); 
        } else {
            currentRange = to_string(start);
        }
        ranges.push_back(currentRange);
        
        return ranges;
    }
};