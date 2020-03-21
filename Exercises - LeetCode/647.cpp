class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> memo(s.length(), vector<bool>(s.length()));
        int counter = 0;

        for (int i = 0; i < s.length(); i++) {
            memo[i][i] = true;
            counter++;
        }

        for (int start = s.length()-1; start >= 0; start--) {
            for (int end = start + 1; end < s.length(); end++) {
                if (s[start] == s[end]) {
                    if (end - start == 1 || memo[start + 1][end - 1]){
                        memo[start][end] = true;
                        counter++;
                    }
                }
            }
        }
        return counter;
    }
};
