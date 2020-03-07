class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        int count = K;
        for(int index = S.length()-1; index >= 0; index--){
            if(S[index]!='-'){
                result+= toupper(S[index]);
                count--;
                if(count==0 && index>0) {
                    result+="-";
                    count = K;
                }
            }
        }
        if(result.back()=='-') result.pop_back();
        reverse(result.begin(),result.end());
        return result;
    }
};
