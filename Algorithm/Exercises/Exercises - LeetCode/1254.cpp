class Solution {
public:
    vector<pair<int,int>> dirs = { {1,0}, {-1,0} , {0,1}, {0,-1} };
    bool res = true;
    int n, m;
    
    void dfs(int i,int j,vector<vector<int>>& grid) {
        grid[i][j] = 1;
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            res = false;
        }
        for (auto dir : dirs) {
            int x = i + dir.first;
            int y = j + dir.second;
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0) {
                dfs(x, y, grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    res = true;
                    dfs(i, j, grid);
                    if (res) count++;
                }
            }
        }
        return count;
    }
};