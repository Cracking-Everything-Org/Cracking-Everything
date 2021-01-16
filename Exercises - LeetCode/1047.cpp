class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        string result;
        for (int i = 0; i < S.length(); i++) {
            if (!stk.empty()) {
                if (stk.top() == S[i]) {
                    stk.pop();
                } else stk.push(S[i]);
            } else stk.push(S[i]);
        }
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
