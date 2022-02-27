// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>
#include <bits/stdc++.h>

int findMaximumDependent(vector<int> &values, vector<bool> &alreadyDepend) {
    int maximum = INT_MIN;
    for (unsigned int i = 0; i < values.size(); i++) {
        if (alreadyDepend[i] == true) {
            maximum = max(maximum, values[i]);
        }
    }
            
    return maximum;
}

vector<int> findMaximumsNonDependent(vector<int> &values, vector<bool> &alreadyDepend) {
    vector<int> result = vector<int>(2, INT_MIN);
    for (unsigned int i = 0; i < values.size(); i++) {
        if (!alreadyDepend[i]) {
            if (values[i] >= result[1]) {
                result[0] = result[1];
                result[1] = values[i];
            }
        }
    }

    return result;
}

int solution(vector<int> &V, vector<int> &A, vector<int> &B) {
    int size = V.size();
    unordered_map<int, vector<int>> dependencies;
    vector<int> values(size, 0);
    vector<bool> alreadyDepend(size, false);
    
    if (size <= 2) {
        return max(max(0, max(V[0], V[1])), V[0] + V[1]);
    }

    for (int i = 0; i < size; i++) {
        dependencies[i] = vector<int>();
    }

    for (unsigned int i = 0; i < B.size(); i++) {
        dependencies[B[i]].push_back(A[i]);
    }
    
    for (int i = 0; i < size; i++) {
        if (dependencies[i].size() == 1) {
            int dependencyValue = dependencies[i][0];
            values[i] = V[i] + V[dependencyValue];
            alreadyDepend[i] = true;
        } else if (dependencies[i].size() == 0) {
            values[i] = V[i];
            alreadyDepend[i] = false;
        } else {
            values[i] = INT_MIN;
            alreadyDepend[i] = true;
        }
    }

    int maxDependent = findMaximumDependent(values, alreadyDepend);
    vector<int> twoMax = findMaximumsNonDependent(values, alreadyDepend);

    return max(max(0, max(maxDependent, twoMax[0] + twoMax[1])), twoMax[1]);
}
