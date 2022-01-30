class Solution {
    int rows = 0, cols = 0;
    void dfs(vector<vector<int>>& A, int i, int j, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || visited[i][j] || !A[i][j]) return;
        visited[i][j] = true;
        q.push({i, j});
        dfs(A, i+1, j, q, visited);
        dfs(A, i-1, j, q, visited);
        dfs(A, i, j+1, q, visited);
        dfs(A, i, j-1, q, visited);
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        rows = A.size();
        cols = A[0].size();

        queue<pair<int, int>>q;
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));
        bool found = false;

        for (int i = 0; i < rows; i++) {
            if (found) break;
            for (int j = 0; j < cols; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j, q, visited);
                    found = true;
                    break;
                }
            }
        }

        vector<int>dirs = {0,-1, 0, 1, 0};
        int dsize = dirs.size()-1;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto f = q.front();
                q.pop();
                for (int d = 0; d < dsize; d++) {
                    int l = f.first + dirs[d];
                    int r = f.second + dirs[d+1];
                    if (l >= 0 && l < rows && r >= 0 && r < cols && !visited[l][r]) {
                        if (A[l][r] == 1) return steps;
                        q.push({l, r});
                        visited[l][r] = true;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
