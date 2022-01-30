class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> ht;
        for (int i=0; i<s.size(); i++){
            if (ht.find(s[i]) != ht.end()){
                ht[s[i]]++;
            } else {
                ht.insert({s[i],1});
            }
        }

        for (int i=0; i<t.size(); i++) {
            if (ht.find(t[i]) == ht.end()) {
                return false;
            } else {
                ht[t[i]]--;
                if(ht[t[i]]<0) return false;
            }
        }
        return true;

    }
};
