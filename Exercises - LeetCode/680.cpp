class Solution {
public:
    bool validPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        return validPalindrome(s, lo, hi, 0);
    }

    bool validPalindrome(string &s, int lo, int hi, int count) {
        if (count > 1) return false;
        while (lo < hi) {
            if (s[lo] == s[hi]) {
                lo++; 
                hi--;
            } else {
                return validPalindrome(s, lo + 1, hi, count + 1) ||
                        validPalindrome(s, lo, hi - 1, count + 1);
            }
        }
        return true;
    }
};
