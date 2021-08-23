class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        if (!nums.size()) return -1;
        
        sort(nums.begin(), nums.end());
        int pairs = 0;
        
        int start = 0;
        for (int end = 1; end < nums.size(); end++) {
            if (nums[end] != nums[end - 1]) {
                pairs += combinations(end - 1 - start);
                start = end;
            } else {
                continue;
            }
        }
        
        return pairs;
    }
};