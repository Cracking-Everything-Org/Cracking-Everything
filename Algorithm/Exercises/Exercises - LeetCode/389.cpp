class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumS = 0;
        for (int i = 0; i< s.length(); i++) sumS -= s[i];
        for (int j = 0; j< t.length(); j++) sumS += t[j];
        return (char)sumS;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> frequency;
        for (char c : s) {
            if (frequency.find(c) == frequency.end()) {
                frequency[c] = 0;
            }
            frequency[c]++;
        }
        for (char c : t) {
            if (frequency.find(c) == frequency.end() || frequency[c] == 0) {
                return c;
            } else {
                frequency[c]--;
            }
        }
        return '-';
    }
};
