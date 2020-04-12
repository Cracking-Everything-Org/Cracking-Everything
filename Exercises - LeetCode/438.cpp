class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length() || !s.length()) return ans;
        int patternHash = 0;
        unordered_map<char,int> originalHT;
        unordered_map<char,int> ht;
        for (int i = 0; i < p.length(); i++) {
            patternHash+= (int)p[i];
            if (originalHT.find(p[i]) != originalHT.end()) {
                originalHT[p[i]]++;
            } else originalHT[p[i]] = 1;
        }

        int startWindow = 0;
        int currentHash = 0;
        for (int endWindow = 0; endWindow < s.length(); endWindow++) {
            currentHash += (int)s[endWindow];
            if (ht.find(s[endWindow]) != ht.end()) {
                ht[s[endWindow]]++;
            } else ht[s[endWindow]] = 1;

            if (endWindow - startWindow + 1 > p.length()) {
                currentHash -= (int)s[startWindow];
                ht[s[startWindow]]--;
                if (ht[s[startWindow]] == 0) {
                    ht.erase(s[startWindow]);
                }
                startWindow++;
            }
            if (endWindow - startWindow + 1 == p.length()) {
                if (currentHash == patternHash) {
                    bool found = false;
                    for (auto entry : ht) {
                        if (originalHT.find(entry.first) == originalHT.end()) break;
                        if (originalHT[entry.first] != entry.second) break;
                        found = true;
                    }
                    if (found) {
                        ans.push_back(startWindow);
                    }
                }
            }
        }
        return ans;
    }
};
