class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(int i=0; i< s.length(); i++){
            result*= 26;
            result+= s[i] - 'A' + 1;
        }
        return result;
    }
};
