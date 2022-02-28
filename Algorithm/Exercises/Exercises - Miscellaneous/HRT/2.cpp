// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int maximumValid;

void dfs(int currentNode, vector<vector<int>> &graph, string &s, int dp[]) {
    vector<int> possiblePathsFromNode;
    dp[currentNode] = 1;

    for (auto it : graph[currentNode]) {
        dfs(it, graph, s, dp);

        if (s[currentNode] != s[it]) {
            possiblePathsFromNode.push_back(dp[it]);
        }
    }

    int size = possiblePathsFromNode.size();
    if (size - 1 >= 0) {
        dp[currentNode] += possiblePathsFromNode[size - 1];
    }
    if (size - 2 >= 0) {
        dp[currentNode] += possiblePathsFromNode[size - 2];
    }

    maximumValid = max(maximumValid, dp[currentNode]);
}

int solution(string &S, vector<int> &A) {
    int size = S.length();
    int dp[size];
    vector<vector<int>> graph(size, vector<int>());
    maximumValid = 0;

    for (int i = 1; i < A.size(); i++) {
        graph[A[i]].push_back(i);
    }

    dfs(0, graph, S, dp);

    return maximumValid;
}
