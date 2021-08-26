class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string& b) { return a.length() < b.length(); });
        
        int longestWordSize = 0;
        unordered_map<string, int> dp;
        for (auto& word : words) {
            for (int i = 0; i < word.length(); i++) { // recorro la palabra y me fijo si existe un substr en DP
                string pre = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], dp[pre] + 1);
            }
            longestWordSize = max(longestWordSize, dp[word]);
        }
        return longestWordSize;
    }
};