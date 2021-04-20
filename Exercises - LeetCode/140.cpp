class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> cache;
        unordered_set<string> dict;
        for (auto entry : wordDict) dict.insert(entry);
        return dfs(s, dict, cache);
    }
    
    vector<string> dfs(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& cache) {
        if (cache.count(s)) return cache[s];
        vector<string> result;
        for (int i = 0; i < s.size(); i++) {
            string temp = s.substr(0, i + 1);
            if (dict.find(temp) != dict.end()) {
                if (i == s.size() - 1) {
                    result.push_back(temp);
                    break;
                }
                vector<string> res = dfs(s.substr(i + 1), dict, cache);
                for (int j = 0; j < res.size(); j++) {
                    result.push_back(temp + " " + res[j]);
                }
            }
        }
        cache[s] = result;
        return result;
    }
};
