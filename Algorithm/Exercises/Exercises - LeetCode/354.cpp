class Solution {
public:
    // Refer to Longest Increasing Subsequence first for better Understanding
    // https://leetcode.com/problems/longest-increasing-subsequence/discuss/1331098/C%2B%2B-or-DP-or-O(n2)
    
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), comp);
		vector<int> dp(envelopes.size(), 1);
		int ans = 1;
        
		for (int i = 0; i < envelopes.size(); i++) {
			for (int j = i+1; j < envelopes.size(); j++) {
				if (envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1]) {
					dp[j]= max(dp[j], dp[i] + 1);
					ans = max(ans, dp[j]);
				}   
			}
		}
		return ans;
	}
    
	static bool comp(const vector<int>&a,const vector<int>&b){
		return a[0]==b[0] ? a[1] > b[1] : a[0] < b[0];
	}
};