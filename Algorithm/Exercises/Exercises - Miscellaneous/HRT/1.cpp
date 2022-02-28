// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(string &S) {
    int size = S.length();
    int i = 0;

    while (i < size - 1) {
        if (S[i] == 'A') {
            if (S[i + 1] == 'B') {
                S = S.substr(0, i) + S.substr(i + 2);
                i = 0;
            } else {
                i++;
            }
        } else if (S[i] == 'B') {
            if (S[i + 1] == 'A') {
                S = S.substr(0, i) + S.substr(i + 2);
                i = 0;
            } else {
                i++;
            }
        } else if (S[i] == 'C') {
            if (S[i + 1] == 'D') {
                S = S.substr(0, i) + S.substr(i + 2);
                i = 0;
            } else {
                i++;
            }
        } else if (S[i] == 'D') {
            if (S[i + 1] == 'C') {
                S = S.substr(0, i) + S.substr(i + 2);
                i = 0;
            } else {
                i++;
            }
        }

        size = S.length();
    }

    return S;
}
