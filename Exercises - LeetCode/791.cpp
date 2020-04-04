class Solution {
public:
    string customSortString(string S, string T) {
        string ans = "";
        vector<int> ht(26, 0);
        unordered_set<char> hs;
        for (int c = 0; c < S.length(); c++) {
            ht[S[c] - 'a'] = 1;
            if (hs.find(S[c]) == hs.end()) {
                hs.insert(S[c]);
            }
        }

        for (int a = 0; a < T.length(); a++) {
            ht[T[a] - 'a']++;
        }

        for (int c = 0; c < S.length(); c++) {
            while (ht[S[c] - 'a'] >= 2) {
                ans += S[c];
                ht[S[c] - 'a']--;
            }
        }
        for (int i=0; i < T.length(); i++) {
            if (hs.find(T[i]) == hs.end()) {
                ans += T[i];
            }
        }

        return ans;
    }
};
