class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string current = "";
            for (int j = 0; j < strs[i].length(); j++) {
                if (j > ans.length()) break;
                if (strs[i][j] == ans[j]) {
                    current += strs[i][j];
                } else {
                    ans = current;
                    break;
                }
            }
            ans = current;
        }
        return ans;
    }
};
