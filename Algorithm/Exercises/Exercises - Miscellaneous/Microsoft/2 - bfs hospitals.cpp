// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <queue>

int solution(int N, vector<int> &A, vector<int> &B, vector<int> &H) {
    vector<int> dis(N, N);
    vector<vector<int>> adj(N);
    queue<int> q;

    int M = B.size();
    int L = H.size();

    for (int i = 0; i < M; ++i) {
        int x = A[i];
        int y = B[i];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(N, false);

    for (int i = 0; i < L; ++i) {
        dis[H[i]] = 0;
        vis[H[i]] = 1;
        q.push(H[i]);
    }

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int x = q.front();
            q.pop();
            for (int j = 0; j < (int)(adj[x].size()); ++j) {
                int y = adj[x][j];
                if (!vis[y]) {
                    vis[y] = true;
                    dis[y] = 1 + dis[x];
                    q.push(y);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, dis[i]);
    }

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            return -1;
        }
    }
    return ans;
}
