class Solution {
public:
    int shortestWay(string s, string t) {
        int numsSubsequences = 0;
        string remaining = t;

        while (remaining.length() > 0) {
            int sIndex = 0;
            int rIndex = 0;
            string subsequence = "";

            while (sIndex < s.length() && rIndex < remaining.length()) {
                if (s[sIndex++] == remaining[rIndex]) {
                    subsequence += remaining[rIndex++];
                }
            }

            if (subsequence.length() == 0) {
                return -1;
            }

            numsSubsequences++;
            remaining = remaining.substr(subsequence.length());

        }

        return numsSubsequences;
    }
};
