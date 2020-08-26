class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        sets.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int setsSize = sets.size();
            for (int j = 0; j < setsSize; j++) {
                vector<int> copy(sets[j]);
                copy.push_back(nums[i]);
                sets.push_back(copy);
            }
        }
        return sets;
    }
};
