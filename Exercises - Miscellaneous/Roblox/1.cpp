#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'pilesOfBoxes' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY boxesInPiles as parameter.
 */

long pilesOfBoxes(vector<int> boxesInPiles) {
    long sum = 0;
    sort(boxesInPiles.begin(), boxesInPiles.end());
    int size = boxesInPiles.size();
    for (int i = 1; i < size; i++) {
        if (boxesInPiles[size - i - 1] != boxesInPiles[size - i]) {
            sum += i;
            cout << sum << endl;
        }
    }
    return sum;
}

int main()
