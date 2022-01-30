class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> groups;
        unordered_map<string, vector<string>> hm;
        
        for (auto str : strings) {
            hm[encode(str)].push_back(str);
        }
        
        for (auto entry : hm) {
            vector<string> current = entry.second;
            sort(current.begin(), current.end());
            groups.push_back(current);
        }
        
        return groups;
    }
    
    string encode(string str) {
        string hash = "";
        int n = str.length();
        for (int i = 1; i < n; i++) {
            int diff = str[i] - str[i - 1];
            if (diff < 0) diff += 26;
            hash += 'a' + diff;
        }
        
        return hash;
    }
};