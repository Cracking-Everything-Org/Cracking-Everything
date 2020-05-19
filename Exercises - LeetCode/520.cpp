class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length()<2) return true;
        if (islower(word[0]) && isupper(word[1])) return false;
        bool shouldBeCaps = isupper(word[1]);
        for (int i=2; i<word.length(); i++) {
            if (shouldBeCaps && islower(word[i])) return false;
            if (!shouldBeCaps && isupper(word[i])) return false;
        }
        return true;
    }
};
