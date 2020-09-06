class Solution {
public:
    bool tryInsert(char candidate, string& s, int pos) {
        if (pos - 1 >= 0) {
            if (s[pos - 1] == candidate) return false;
        }
        if (pos + 1 < s.length()) {
            if (s[pos + 1] == candidate) return false;
        }
        return true;
    }

    void insertPossible(string& s, int pos) {
        for (int i = 0; i <= 26; i++) {
            char x = 'a' + i;
            if (tryInsert(x, s, pos)) {
                s[pos] = x;
                return;
            }
        }
        return;
    }

    string modifyString(string s) {
        string copy = s;
        for (int i = 0; i < copy.length(); i++) {
            if (copy[i] == '?') {
                insertPossible(copy, i);
            }
        }

        return copy;
    }
};
