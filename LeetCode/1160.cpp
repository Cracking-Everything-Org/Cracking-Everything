class Solution {
public:
    bool goodString(unordered_map<char, int> iterationHT, unordered_map<char, int> ht){
        for(auto it: iterationHT){
            if(ht.find(it.first)== ht.end()) return false;
            if(ht[it.first] < it.second) return false;
        }
        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> ht;
        int result = 0;
        for(auto c: chars) ht[c]++;
        for(auto s: words){
            unordered_map<char, int> iterationHT;
            for(auto ch: s) iterationHT[ch]++;
            if(goodString(iterationHT, ht)) result += s.length();
        }
        return result;
    }
};
