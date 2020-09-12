#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int, string> hm;
    hm[1] = "one";
    hm[2] = "two";
    hm[3] = "three";
    hm[4] = "four";
    hm[5] = "five";
    hm[6] = "six";
    hm[7] = "seven";
    hm[8] = "eight";
    hm[9] = "nine";

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n <= 9) {
        cout << hm[n] << endl;
    } else {
        cout << "Greater than 9" << endl;
    }

    return 0;
}
