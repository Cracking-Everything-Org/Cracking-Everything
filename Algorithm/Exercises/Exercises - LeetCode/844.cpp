class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stkS;
        stack<char> stkT;

        for (int i = 0; i < S.length(); i++) {
            if (S[i] != '#') {
                stkS.push(S[i]);
            } else {
                if (!stkS.empty()) {
                    stkS.pop();
                }

            }
        }

        string resS = "";
        while (!stkS.empty()) {
            resS += stkS.top();
            stkS.pop();
        }

        for (int i = 0; i < T.length(); i++) {
            if (T[i] != '#') {
                stkT.push(T[i]);
            } else {
                if (!stkT.empty()) {
                    stkT.pop();
                }

            }
        }

        string resT = "";
        while (!stkT.empty()) {
            resT += stkT.top();
            stkT.pop();
        }

        if (resS.length() != resT.length()) return false;

        for (int i = 0; i < resS.length(); i++) {
            if (resS[i] != resT[i]) return false;
        }

        return true;
    }
};
