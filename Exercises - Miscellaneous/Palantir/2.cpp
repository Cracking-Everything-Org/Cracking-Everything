#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'findRiskScores' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY elevations as parameter.
 */

bool highPoint (vector<vector<int>> elevations, int row, int col) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
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


void bfs(pair<int, int> currentV, vector<vector<int>>& riskScores, int n, int m, vector<vector<int>> elevations) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> toProcess;
    toProcess.push(currentV);

    while (!toProcess.empty()) {
        pair<int, int> current = toProcess.front();
        toProcess.pop();
        if (!visited[current.first][current.second]) {
            riskScores[current.first][current.second]++;
            visited[current.first][current.first] = true;
            int row = current.first;
            int col = current.second;

            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (row + i >= 0 && row + i < elevations.size() && col + j >= 0 && col + j < elevations[0].size()) {
                        if (elevations[row + i][col + i] < elevations[row][col]) {
                            toProcess.push(make_pair(row + i, col + i));
                        }
                    }
                }
            }
        }
    }
}

vector<vector<int>> findRiskScores(vector<vector<int>> elevations) {
    vector<vector<int>> riskScores(elevations.size(), vector<int>(elevations[0].size(), 0));
    vector<vector<bool>> highPoints = findHighPoints(elevations);

    queue<pair<int, int>> toProcess;
    for (int i = 0; i < highPoints.size(); i++) {
        for (int j = 0; j < highPoints[0].size(); j++) {
            if (highPoints[i][j]) {
                toProcess.push(make_pair(i,j));
            }
        }
    }

    while (!toProcess.empty()) {
        bfs(toProcess.front(), riskScores, elevations.size(), elevations[0].size(), elevations);
        toProcess.pop();
    }

    return riskScores;
}
