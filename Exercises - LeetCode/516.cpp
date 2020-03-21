class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(!s.length()) return 0;
        vector<vector<int>> memo(s.length(), vector<int>(s.length(), -1));
        return findLPS(s, memo, 0, s.length()-1);
    }

    int findLPS(string& s, vector<vector<int>>& memo, int start, int end) {
        if (start > end) return 0;
        if (start == end) memo[start][end] = 1;

        if (memo[start][end] == -1) {
            if (s[start] == s[end]) {
                memo[start][end] = 2 + findLPS(s, memo, start + 1, end - 1);
            } else {
                int c1 = findLPS(s, memo, start + 1, end);
                int c2 = findLPS(s, memo, start, end - 1);
                memo[start][end] = max(c1, c2);
            }
        }

        return memo[start][end];
    }
};
