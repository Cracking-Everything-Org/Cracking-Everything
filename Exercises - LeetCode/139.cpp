class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // DP
        vector<bool> isWordBreak(s.length()+1);
        isWordBreak[0] = true;
        for (int i = 0; i < s.length() + 1; i++) {
            for (int j = 0; j < i; j++) {
                //
                if (!isWordBreak[j]){
                    continue;
                }

                if (count(wordDict.begin(), wordDict.end(), s.substr(j, i))) {
                    isWordBreak[i] = true;
                    break;
                }
            }
        }
        return isWordBreak[s.length()];
    }
};
