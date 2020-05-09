class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int N = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        vector<vector<string>> dp(N + 1, vector<string>());
        dp[0].emplace_back("");
        for(int i = 1; i <= N; ++i){
            for(int j = 0; j < i; ++j){
                string substr = s.substr(j, i - j);
                if(dp[j].size() > 0 && wordSet.find(substr) != wordSet.end()){
                    for(string& l : dp[j]){
                        dp[i].emplace_back(l + (l == "" ? "" : " ") + substr);
                    }
                }
            }
        }

        return dp[N];
    }
};
