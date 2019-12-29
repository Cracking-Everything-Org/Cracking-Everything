class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string resultS;
        for(int i=0; i< S.length(); i++){
            if(S[i]!= '#'){
               resultS+= S[i];
            } else if(resultS.length()>0) resultS.pop_back();
        }
        string resultT;
        for(int i=0; i< T.length(); i++){
            if(T[i]!= '#'){
               resultT+= T[i];
            } else if(resultT.length()>0) resultT.pop_back();
        }
        return resultS == resultT;
    }
};
