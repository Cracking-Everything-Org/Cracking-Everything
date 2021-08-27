class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> seen(m, vector<int>(n, INT_MAX));
        
        queue<vector<int>> q;
        q.push({0, 0, 0});
        seen[0][0] = 0;
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                vector<int> current = q.front();
                q.pop();
                int row = current[0];
                int col = current[1];
                if (row == m - 1 && col == n - 1) return steps;
                
                for (auto dir : dirs) {
                    int r = row + dir[0];
                    int c = col + dir[1];
                    if (r >= 0 && c >= 0 && r < m && c < n) {
                        int obstacles = current[2] + grid[r][c];
                        if (obstacles > k || obstacles >= seen[r][c]) continue;
                        seen[r][c] = obstacles;
                        q.push({r, c, obstacles});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};