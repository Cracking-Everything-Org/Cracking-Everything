class Solution {
public:
    // TWO POINTERS

    int expressiveWords(string S, vector<string>& words) {
        int counter = 0;

        for (auto word : words) {
            if (checkScratchy(S, word)) {
                counter++;
            }
        }

        return counter;
    }

    bool checkScratchy(string S, string word) {
        int startS = 0;
        int endS = 0;

        int startW = 0;
        int endW = 0;

        while (endS < S.length() && endW < word.length()) {
            if (S[startS] != word[startW]) {
                return false;
            }

            while (endS < S.length() && S[startS] == S[endS]) {
                endS++;
            }

            while (endW < word.length() && word[startW] == word[endW]) {
                endW++;
            }

            int n1 = endS - startS;
            int n2 = endW - startW;

            if (n1 < n2 || (n1 < 3 && n1 != n2)) {
                return false;
            }

            startS = endS;
            startW = endW;
        }
        if (startS == S.length() && startW == word.length()) {
            return true;
        } else {
            return false;
        }

    }
};
