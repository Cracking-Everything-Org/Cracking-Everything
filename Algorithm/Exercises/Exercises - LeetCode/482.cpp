class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string license = "";
        int remaining = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (remaining >= K) {
                license += '-';
                remaining = 0;
            }
            if (S[i] != '-') {
                if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z')) {
                    license += toupper(S[i]);
                } else {
                    license += S[i];
                }
                remaining++;
            }
        }
        reverse(license.begin(), license.end());
        int start = 0;
        while (start < license.size()) {
            if (license[start] == '-') {
                start++;
            } else break;
        }
        return license.substr(start);
    }
};
