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


class Solution {
public:
    bool validPalindrome(string s) {
        bool foundDifference = false;
        return checkPalindrome(s, 0, s.length() - 1, foundDifference);
    }
    
    bool checkPalindrome(string s, int left, int right, bool& foundDifference) {
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                if (foundDifference) {
                    return false;
                }
                foundDifference = true;
                return checkPalindrome(s, left + 1, right, foundDifference) 
                    || checkPalindrome(s, left, right - 1, foundDifference);
            }
        }
        return true;
    }
};