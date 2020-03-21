class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length() + 1, vector<int>(text2.length() + 1,0));

        int maxLength = 0;
        for (int i=1; i <= text1.length(); i++) {
            for (int j=1; j <= text2.length(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    memo[i][j] = 1 + memo[i-1][j-1];
                } else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
                maxLength = max(maxLength, memo[i][j]);
            }
        }
        return maxLength;
    }
};
