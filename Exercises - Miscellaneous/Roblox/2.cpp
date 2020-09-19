#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'prison' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. INTEGER_ARRAY h
 *  4. INTEGER_ARRAY v
 */

long prison(int n, int m, vector<int> h, vector<int> v) {
    vector <bool> x(n+1, 1);
    vector <bool> y(m+1, 1);
    long cx = 0;
    long ox = INT_MIN;
    long cy = 0;
    long oy = INT_MIN;

    for (int i = 0; i < h.size(); i++) {
        x[h[i]] = 0;
    }

    for (int i =0 ;i < v.size(); i++) {
        y[v[i]] = 0;
    }

    for (int i = 1;i <= n; i++) {
        if (x[i])
            cx = 0;
        else {
            cx++;
            ox = max(ox, cx);
        }
    }

    for (int i = 1;i <= m; i++) {
        if (y[i]) {
            cy= 0;
        } else {
            cy++;
            oy = max(oy, cy);
        }
    }
    return (ox + 1) * (oy + 1);
}

int main()
