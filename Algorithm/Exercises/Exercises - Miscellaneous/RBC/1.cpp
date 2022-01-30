#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countCounterfeit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY serialNumber as parameter.
 */

int countCounterfeit(vector<string> serialNumber) {

    unordered_set<int> currencyDenomination;
    currencyDenomination.insert(10);
    currencyDenomination.insert(20);
    currencyDenomination.insert(50);
    currencyDenomination.insert(100);
    currencyDenomination.insert(200);
    currencyDenomination.insert(500);
    currencyDenomination.insert(1000);

    int total = 0;
    bool valid = true;
    int pos = 0;
    int endYear = 0;
    int year = 0;
    for (int i = 0; i < serialNumber.size(); i++) {
        unordered_set<char> firstThreeCharacter;
        valid = true;
        pos = 0;
        if (serialNumber[i].size() < 10 || serialNumber[i].size() > 12) {
            valid = false;
        }
        while (pos < 3) {
            if (firstThreeCharacter.count(serialNumber[i][pos]) || serialNumber[i][pos] < 'A' || serialNumber[i][pos] > 'Z') {
                valid = false;
            } else {
                firstThreeCharacter.insert(serialNumber[i][pos]);
            }
            pos++;
        }
        endYear = pos + 4;
        year = 0;
        while (pos < endYear) {
            if (serialNumber[i][pos] >= '0' && serialNumber[i][pos] <= '9') {
                year = (year * 10) + (serialNumber[i][pos] - '0');
            } else {
                valid = false;
            }
            pos++;
        }
        if (year < 1900 || year > 2019) {
            valid = false;
        }
        int denomination = 0;
        while (pos < serialNumber[i].size() - 1) {
            if (serialNumber[i][pos] >= '0' && serialNumber[i][pos] <= '9') {
                denomination = (denomination * 10) + (serialNumber[i][pos] - '0');
            } else {
                valid = false;
            }
            pos++;
        }
        if (!currencyDenomination.count(denomination)) {
            valid = false;
        }
        if (serialNumber[i][pos] < 'A' || serialNumber[i][pos] > 'Z') {
            valid = false;
        }
        if (valid) {
            total += denomination;
        }
    }
    return total;
}
