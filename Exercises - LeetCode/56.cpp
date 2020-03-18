class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int itr = 0;
        int start = intervals[itr][0];
        int end = intervals[itr][1];

        while (itr < intervals.size()-1) {
            itr++;
            if (intervals[itr][0] <= end) {
                end = max(end, intervals[itr][1]);
            } else {
                ans.push_back({start,end});
                start = intervals[itr][0];
                end = intervals[itr][1];
            }
        }
        ans.push_back({start,end});

        return ans;
    }
};
