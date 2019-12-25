class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ht;
        for (int i=0; i< s.size(); i++) {
            if (ht.find(s[i]) != ht.end()) {
                ht[s[i]]++;
            } else {
                ht.insert({s[i],1});
            }
        }
        for (int i=0; i< s.size(); i++) {
            if (ht[s[i]] == 1) return i;
        }
        return -1;
    }
};
