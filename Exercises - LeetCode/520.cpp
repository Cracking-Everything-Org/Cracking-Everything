class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if (n == 1) return true;
        bool firstIsCapital = word[0] >= 'A' && word[0] <= 'Z';
        bool secondIsCapital = word[1] >= 'A' && word[1] <= 'Z';
        if (!firstIsCapital && secondIsCapital) return false;
        for (int i = 2; i < n; i++) {
            if (secondIsCapital) {
               if (word[i] < 'A' || word[i] > 'Z') return false;
            } else {
                if (word[i] >= 'A' && word[i] <= 'Z') return false;
            }
        }
        return true;
    }
};
