#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
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

    int a, b;

    cin >> a;
    cin >> b;

    for (int n = a; n <= b; n++) {
        if (n <= 9) {
            cout << hm[n] << endl;
        } else if (n % 2 == 0) {
            cout << "even" << endl;
        } else {
            cout << "odd" << endl;
        }
    }

    return 0;
}
