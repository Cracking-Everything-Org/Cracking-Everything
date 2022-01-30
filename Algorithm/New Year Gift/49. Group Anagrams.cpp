class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;
        vector<vector<string>> groups;
        for (string str : strs) {
            string original = str;
            sort(str.begin(), str.end());
            if (hm.find(str) == hm.end()) {
                hm[str] = vector<string>();
            }
            hm[str].push_back(original);
        }
        
        for (auto entry : hm) {
            groups.push_back(entry.second);
        }
        
        return groups;
    }
};