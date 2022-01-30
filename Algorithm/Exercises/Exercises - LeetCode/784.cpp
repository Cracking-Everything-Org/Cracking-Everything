class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> results;
        queue<string> permutations;
        permutations.push("");

        for (int i = 0; i < S.length(); i++) {
            int n = permutations.size();

            for (int j = 0; j < n; j++) {
                string oldPermutation = permutations.front();
                permutations.pop();

                if (isalpha(S[i])) {
                    string newLower(oldPermutation);
                    newLower += tolower(S[i]);

                    string newUpper(oldPermutation);
                    newUpper += toupper(S[i]);

                    if (newLower.size() == S.length() && newUpper.size() == S.length()) {
                        results.push_back(newLower);
                        results.push_back(newUpper);
                    } else {
                        permutations.push(newLower);
                        permutations.push(newUpper);
                    }
                } else {
                    oldPermutation += S[i];
                    if (oldPermutation.size() == S.length()) {
                        results.push_back(oldPermutation);
                    } else {
                        permutations.push(oldPermutation);
                    }
                }

            }
        }
        return results;
    }
};
