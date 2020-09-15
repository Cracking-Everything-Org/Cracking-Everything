class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int count = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != ' ') count++;
            else {
                if (count == 0) continue;
                else return count;
            }
        }
        return count;
    }
};
