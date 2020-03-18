class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '}') {
                if (!stk.size()) return false;
                if (stk.top() == '{') {
                    stk.pop();
                } else return false;
            } else if (s[i] == ']') {
                if (!stk.size()) return false;
                if (stk.top() == '[') {
                    stk.pop();
                } else return false;
            } else if (s[i] == ')') {
                if (!stk.size()) return false;
                if (stk.top() == '(') {
                    stk.pop();
                } else return false;
            } else stk.push(s[i]);
        }
        return stk.size() == 0;
    }
};
