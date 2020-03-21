class Solution {
public:
    int longestStrChain(vector<string>& words) {
       sort(words.begin(), words.end(), [](string &a, string& b) {return a.length() < b.length();});

        int res = 0;
        unordered_map<string, int> dp;
        for(auto & t : words) {
            for(int i = 0; i < t.length(); i++) {
                string pre = t.substr(0, i) + t.substr(i+1);
                dp[t] = max(dp[t], dp[pre]+1);
            }
            res = max(res, dp[t]);
        }
        return res;
    }
};
