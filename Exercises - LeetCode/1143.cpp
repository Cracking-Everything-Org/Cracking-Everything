class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length(), vector<int>(text2.length(), -1));
        return LCS(text1, text2, 0, 0, memo);
    }

    int LCS(string& text1, string& text2, int index1, int index2, vector<vector<int>>& memo) {
        if (index1 == text1.length() || index2 == text2.length()) {
            return 0;
        }
        if (memo[index1][index2] == -1) {
            if (text1[index1] == text2[index2]) {
                memo[index1][index2] = 1 + LCS(text1, text2, index1 + 1, index2 + 1, memo);
            } else {
                int c1 = LCS(text1, text2, index1, index2 + 1, memo);
                int c2 = LCS(text1, text2, index1 + 1, index2, memo);
                memo[index1][index2] = max(c1, c2);
            }
        }

        return memo[index1][index2];
    }
};
