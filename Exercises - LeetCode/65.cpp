class Solution {
public:
    bool isNumber(string s) {
        //trim
        int firstNotSpace = 0;
        int lastNotSpace = s.length()-1;
        while(s[firstNotSpace] == ' ' && firstNotSpace < lastNotSpace) firstNotSpace++;
        while(s[lastNotSpace] == ' ' && lastNotSpace > firstNotSpace) lastNotSpace--;

        bool eSeen = false;
        bool numSeen = false;
        bool dotSeen = false;

        if(!isdigit(s[lastNotSpace])) return false;

        for (int i = firstNotSpace; i <= lastNotSpace; i++) {
            if (isdigit(s[i])) {
                numSeen = true;
            } else if (s[i] == 'e') {
                if (eSeen || !numSeen) return false;
                eSeen = true;
                numSeen = false;
            } else if (s[i] == '.') {
                if(eSeen || dotSeen) return false;
                dotSeen = true;
            } else if (s[i] == '-' || s[i] == '+') {
                if(i != firstNotSpace || s[i-1] != 'e') return false;
            } else return false;
        }
        return numSeen;
    }
};
