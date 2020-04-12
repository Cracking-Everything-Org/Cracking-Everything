class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> ht;
        for (int i = 0; i < s.length(); i++) {
            if (ht.find(s[i]) != ht.end()) {
                ht[s[i]]++;
            } else ht[s[i]] = 1;
        }

        int maxSingle = 0;
        int longest = 0;
        int singleFound = false;
        for (auto entry : ht) {
            if (entry.second % 2 == 0) {
                longest += entry.second;
            } else {
                longest += entry.second - 1;
                singleFound = true;
            }
        }
        return singleFound ? longest + 1 : longest;
    }
};
