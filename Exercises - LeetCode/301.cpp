class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        removeHelper(s, result, 0, 0, {'(', ')'});
        return result;
    }
    
    void removeHelper(string s, vector<string> &result, int start, int lastRemovedIndex, pair<char, char> par) {
        for (int stack = 0, i = start; i < s.size(); i++) {
            // check for valid parentheses.
            if (s[i] == par.first) stack++;
            if (s[i] == par.second) stack--;
            if (stack >= 0) continue;   // we have valid parentheses till now.
            // From HERE, we have invalid parentheses.
            for (int j = lastRemovedIndex; j <= i; j++) {
                if (s[j] == par.second && (j == lastRemovedIndex || s[j-1] != par.second)) { // ')' parentheses and not consecutive.
                    // remove current parentheses from string and recurse.
                    string str = s.substr(0, j) + s.substr(j + 1, s.size() - j - 1);
                    removeHelper(str, result, i, j, par);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());    // reverse string if going right to left.
        if (par.first == '(') removeHelper(s, result, 0, 0, {')', '('});  // give new string
        else result.push_back(s);   // left to right.
    }
};