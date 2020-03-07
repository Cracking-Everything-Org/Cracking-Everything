class Solution {
public:
    bool checkValidString(string s) {
        int miin = 0;
        int maax = 0;
        for(int i=0; i< s.length(); ++i){
            if(s[i] == '('){
                miin ++; maax ++;
            } else if(s[i] == ')'){
                maax --;
                miin = max(miin-1, 0);
            } else if(s[i] == '*'){
                maax ++;
                miin = max(miin-1, 0);
            }  
            if(maax < 0) return false;
        }
        return miin == 0;
    }
};