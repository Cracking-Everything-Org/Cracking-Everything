class Solution {
public:
    string reverseStr(string &toReverse) {
        for (int i = 0; i < toReverse.length()/2; i++) {
            swap(toReverse[i], toReverse[toReverse.length()-1-i]);
        }
        return toReverse;
    }

    string reverseWords(string s) {
        string result;
        string toReverse;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                toReverse += s[i];
            } else {
                result += reverseStr(toReverse);
                result += " ";
                toReverse = "";
            }
        }
        result += reverseStr(toReverse);
        return result;
    }
};
