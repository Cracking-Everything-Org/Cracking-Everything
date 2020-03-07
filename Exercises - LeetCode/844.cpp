class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stkS;
        for(int i=0; i<S.length(); i++){
            if(S[i]=='#'){
                if(!stkS.empty()) stkS.pop();
            } else {
                stkS.push(S[i]);
            }
        }

        stack<char> stkT;
        for(int i=0; i<T.length(); i++){
            if(T[i]=='#'){
                if(!stkT.empty()) stkT.pop();
            } else {
                stkT.push(T[i]);
            }
        }

        while(!stkS.empty() && !stkT.empty()){
            if(stkS.top() != stkT.top()) return false;
            stkS.pop();
            stkT.pop();
        }
        return stkS.empty() && stkT.empty();
    }
};
