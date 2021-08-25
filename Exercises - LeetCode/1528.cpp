class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string restored = s;
        
        for (int i = 0; i < indices.size(); i++) {
            restored[indices[i]] = s[i];
        }
        
        return restored;
    }
};