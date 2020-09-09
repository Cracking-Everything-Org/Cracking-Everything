class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        unordered_map<char, char> dp;
        for (int i = 0; i < str1.length(); i++) {
            if (dp[str1[i]] != NULL && dp[str1[i]] != str2[i]) {
                return false;
            }
            dp[str1[i]] = str2[i];
        }
        return set(str2.begin(), str2.end()).size() < 26;
    }
};
