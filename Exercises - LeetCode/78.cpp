class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());

        for (auto num : nums) {
            int n = ans.size();
            for (int i = 0; i < n; i++) {
                vector<int> copy(ans[i]);
                copy.push_back(num);
                ans.push_back(copy);
            }
        }
        return ans;
    }
};
