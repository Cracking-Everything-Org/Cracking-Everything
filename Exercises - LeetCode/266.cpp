class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> frequency;
        bool oddFound = false;
        for (int i = 0; i < s.length(); i++) {
            if (frequency.find(s[i]) != frequency.end()) {
                frequency[s[i]]++;
            } else {
                frequency[s[i]] = 1;
            }
        }
        for (auto entry : frequency) {
            if (entry.second % 2 != 0) {
                if (oddFound) {
                    return false;
                }
                oddFound = true;
            }
        }
        return true;
    }
};
