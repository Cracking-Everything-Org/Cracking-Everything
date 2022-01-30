class Solution {
public:
    string reverseOnlyLetters(string S) {
        string copy = str.copy(S);
        int last = S.length() - 1;
        int first = 0;
        while (first < last) {
            while (!isalpha(S[first]) && first < last) first++;
            while (!isalpha(S[last]) && first < last) last--;
            swap(S[first], S[last]);
        }
        return S;
    }
};
