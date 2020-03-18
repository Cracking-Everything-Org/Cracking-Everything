class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        int startPointer = 0;
        int endPointer = 0;
        for (int num = 0; num < nums.size(); num++) {
            startPointer = 0;
            if (num > 0  && nums[num] == nums[num-1]) {
                startPointer = endPointer + 1;
            }

            endPointer = ans.size()-1;

            for (int i = startPointer; i <= endPointer; i++) {
                vector<int> current(ans[i]);
                current.push_back(nums[num]);
                ans.push_back(current);
            }
        }
        return ans;
    }
};
