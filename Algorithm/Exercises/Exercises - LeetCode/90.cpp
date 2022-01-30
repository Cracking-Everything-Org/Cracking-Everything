class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        subsets.push_back(vector<int>());

        int startIndex = 0, endIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            startIndex = 0;

            if (i > 0 && nums[i] == nums[i - 1]) {
                startIndex = endIndex + 1;
            }
            endIndex = subsets.size() - 1;

            for (int j = startIndex; j <= endIndex; j++) {
                vector<int> copy(subsets[j]);
                copy.push_back(nums[i]);
                subsets.push_back(copy);
            }
        }
        return subsets;
    }
};
