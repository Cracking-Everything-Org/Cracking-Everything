class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ht;
        for (auto c : s) {
            if (ht.find(c) == ht.end()) {
                ht[c] = 1;
            } else {
                ht[c]++;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (ht[s[i]] == 1) return i;
        }
        return -1;
    }
};
