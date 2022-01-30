#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'findHighPoints' function below.
 *
 * The function is expected to return a 2D_BOOLEAN_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY elevations as parameter.
 */

bool highPoint (vector<vector<int>> elevations, int row, int col) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            cout << "i: " << i << endl;
            cout << "j: " << j << endl;
            if (row + i >= 0 && row + i < elevations.size() && col + j >= 0 && col + j < elevations[0].size()) {
                if (elevations[row + i][col + j] >= elevations[row][col] && !(row + i == row && col + j == col)) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<vector<bool>> findHighPoints(vector<vector<int>> elevations) {
    vector<vector<bool>> highPoints(elevations.size(), vector<bool>(elevations[0].size(), false));
    for (int row = 0; row < elevations.size(); row++) {
        for (int col = 0; col < elevations[0].size(); col++) {
            if (highPoint(elevations, row, col)) {
                highPoints[row][col] = true;
            }
        }
    }

    return highPoints;
}
