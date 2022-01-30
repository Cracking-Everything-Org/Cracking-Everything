class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // DP
        vector<bool> isWordBreak(s.length()+1);
        isWordBreak[0] = true;
        for (int i = 0; i < s.length() + 1; i++) {
            for (int j = 0; j < i; j++) {
                //
                if (!isWordBreak[j]){
                    continue;
                }

                if (count(wordDict.begin(), wordDict.end(), s.substr(j, i))) {
                    isWordBreak[i] = true;
                    break;
                }
            }
        }
        return isWordBreak[s.length()];
    }
};


class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
		vector<bool> dp(n + 1);
		dp[0] = true; // empty siempre está incluido
        unordered_set<string> dict; // hago un dict para saber rapidamente si ya encontré el substring
        for (auto entry : wordDict) dict.insert(entry);

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i)) != dict.end()) {
                    dp[i] = true; // marco que encontré hasta ese indice
                    break;
                }
            }
        }
        
        return dp[n];
	}
};