class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (auto interval : intervals) {
            if (ans.size() == 0 || ans[ans.size()-1][1] < interval[0]) {
                ans.push_back(interval);
            } else {
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], interval[1]);
            }
        }
        return ans;
    }
};
