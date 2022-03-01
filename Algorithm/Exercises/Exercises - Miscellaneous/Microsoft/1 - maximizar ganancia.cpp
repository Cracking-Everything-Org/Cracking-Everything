// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

int findMaximumDependent(vector<int> &values) {
    int maximum = 0;
    for (int i = 0; i < values.size(); i++) {
        maximum = max(maximum, values[i]);
    }

    return maximum;
}

vector<int> findMaximumsNonDependent(vector<int> &values) {
    vector<int> result = vector<int>(2, INT_MIN);
    for (int i = 0; i < values.size(); i++) {
        if (values[i] >= result[1]) {
            result[0] = result[1];
            result[1] = values[i];
        }
    }

    return result;
}

void calculate(int i, vector<int> &V, unordered_map<int, vector<int>> &dependencies, vector<int> &dependentValues, vector<int> &simpleValues) {
    int depSize = dependencies[i].size();
    if (depSize == 0) {
        simpleValues.push_back(V[i]);
    } else {
        if (depSize > 1) {
            return ;
        } else {
            int current = dependencies[i][0];
            if (dependencies[current].size()) {
                return ;
            } else {
                dependentValues.push_back(V[i] + V[current]);
            }
        }
    }
}

int solution(vector<int> &V, vector<int> &A, vector<int> &B) {
    int size = V.size();
    unordered_map<int, vector<int>> dependencies;
    vector<int> dependentValues;
    vector<int> simpleValues;

    if (size == 0) return 0;
    if (size == 1) return max(0, V[0]);
    if (size == 2) return max(max(0, max(V[0], V[1])), V[0] + V[1]);

    for (int i = 0; i < size; i++) {
        dependencies[i] = vector<int>();
    }

    for (int i = 0; i < B.size(); i++) {
        dependencies[B[i]].push_back(A[i]);
    }

    for (int i = 0; i < size; i++) {
        calculate(i, V, dependencies, dependentValues, simpleValues);
    }

    int maxDependent = findMaximumDependent(dependentValues);
    vector<int> twoMax = findMaximumsNonDependent(simpleValues);

    return max(max(0, max(maxDependent, twoMax[0] + twoMax[1])), twoMax[1]);
}
