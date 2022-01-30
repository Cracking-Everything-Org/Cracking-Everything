class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        unordered_map<int, vector<string>> hm;
        
        for (int i = 0; i < indices.size(); i++) {
            string source = sources[i];
            string target = targets[i];
            int startIndex = indices[i];
            
            if (s.substr(startIndex, source.length()) == source) {
                hm[startIndex].push_back(source);
                hm[startIndex].push_back(target);
            }
        }
        
        int start = 0;
        string result = "";
        
        while (start < s.length()) {
            if (hm.find(start) != hm.end()) {
                result += hm[start][1];
                start += hm[start][0].length();
            } else {
                result += s[start];
                start++;
            }
        }
       
        return result;
    }
};