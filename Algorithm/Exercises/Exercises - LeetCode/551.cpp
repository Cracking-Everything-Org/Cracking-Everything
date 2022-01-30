class Solution {
public:
    bool checkRecord(string s) {
        int absentCounter = 0;
        int lateCounter = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                absentCounter++;
                if (absentCounter > 1) return false;
            }
            else if (s[i] == 'L') {
                lateCounter++;
                if (lateCounter > 2 && i > 1 && s[i-1] == 'L' && s[i-2] == 'L') {
                    return false;
                }
            }
        }
        return true;
    }
};
