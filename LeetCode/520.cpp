class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()==0 || word.length()==1) return true;
        if(!isupper(word[0]) && isupper(word[1])) return false;
        bool mayuscula = isupper(word[0]) && isupper(word[1]);
        bool minuscula = !isupper(word[1]);
        for(int i=2; i< word.length(); i++){
            if(!isupper(word[i]) && mayuscula){
                return false;
            } else if(isupper(word[i]) && minuscula) {
                return false;
            }
        }
        return true;
    }
};
