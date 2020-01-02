class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ']') {
                if (stk.empty()) return false;
                if (stk.top() != '[' ) return false;
                stk.pop();
            } else if (s[i] == ')'){
                if (stk.empty()) return false;
                if (stk.top()!= '(') return false;
                stk.pop();
            } else if (s[i] == '}') {
                if (stk.empty()) return false;
                if (stk.top()!= '{') return false;
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};
