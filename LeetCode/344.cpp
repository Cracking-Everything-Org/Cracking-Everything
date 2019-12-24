class Solution {
public:
    void reverseString(vector<char>& s) {
        char cup;
        int sLength = s.size();
        if(sLength == 0) return;
        for (int i=0; i<=(sLength-1)/2; i++) {
            cup = s[i];
            s[i] = s[sLength-i-1];
            s[sLength-i-1] = cup;
        }
    }
};
