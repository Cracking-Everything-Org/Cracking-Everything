#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'consecutive' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER num as parameter.
 */

int consecutive(long num) {
    int res = 1;
    int count;
    while (num % 2 == 0) num /= 2;
    for (long i = 3; i * i <= num; res *= count + 1, i += 2)
        for (count = 0; num % i == 0; num /= i, count++);
    return (num == 1 ? res : res * 2) - 1;
}

int main()
