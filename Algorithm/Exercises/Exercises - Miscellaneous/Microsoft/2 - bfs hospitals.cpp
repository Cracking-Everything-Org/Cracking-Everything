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

int solution(int N, vector<int> &A, vector<int> &B, vector<int> &H) {
    int distance = 0;

    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < N; i++) {
        graph[i] = vector<int>();
    }

    for (unsigned int i = 0; i < A.size(); i++) {
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
    }
    
    unordered_set<int> visited;
    queue<int> q;
    int visitedCities = 0;
    
    for (auto hospital : H) {
        q.push(hospital);
        graph[hospital].push_back(hospital);
        visitedCities++;
        visited.insert(hospital);
    }

    for (auto entry : graph) {
        if (entry.second.size() == 0) return -1;
    }

    while (!q.empty()) {
        distance++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int current = q.front();
            q.pop();
            if (visited.find(current) == visited.end()) {
                visited.insert(current);
                visitedCities++;
            }

            for (auto city : graph[current]) {
                if (visited.find(city) == visited.end()) {
                    q.push(city);
                }
            }
        }
    }

    return visitedCities == N ? distance - 1 : -1;
}
