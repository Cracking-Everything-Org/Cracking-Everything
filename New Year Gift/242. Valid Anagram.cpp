class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> frequency;
        
        for (auto c : s) {
            frequency[c]++;
        }
        
        for (auto c : t) {
            if (frequency.find(c) != frequency.end()) {
                frequency[c]--;
                if (frequency[c] == 0) {
                    frequency.erase(c);
                }
            } else {
                return false;
            }
        }
        
        return true;
    }
};