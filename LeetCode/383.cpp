class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ht;
        for(auto c : magazine){
            if(ht.find(c)!=ht.end()) ht[c]++;
            else ht[c]=1;
        }
        for(auto r : ransomNote){
            if(ht.find(r)!=ht.end()) {
                ht[r]--;
                if(ht[r]==0) ht.erase(r);
            } else return false;
        }
        return true;
    }
};
