class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumS = 0;
        for (int i = 0; i< s.length(); i++) sumS -= s[i];
        for (int j = 0; j< t.length(); j++) sumS += t[j];
        return (char)sumS;
    }
};
