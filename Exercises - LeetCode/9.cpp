class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string xs = to_string(x);
        for (int i = 0; i < xs.length(); i++) {
            if (xs[i] != xs[xs.length() -1 -i]) return false;
        }
        return true;
    }
};
