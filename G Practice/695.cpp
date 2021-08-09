class Solution {
    vector<int> x = {-1, 0, 0, 1};
    vector<int> y = {0, 1, -1, 0};
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        if (!grid.size() || !grid[0].size()) return maxArea;
        
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    int current = 0;
                    bfs(row, col, grid, current, maxArea);
                }
            }
        }
        
        return maxArea;
    }
    
    void bfs(int row, int col, vector<vector<int>> &grid, int &current, int &maxArea) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return;
        }
        
        if (grid[row][col] == 1) {
            current++;
            grid[row][col] = 0;
        }
        
        maxArea = max(maxArea, current);
        
        for (int i = 0; i < 4; i++) {
            bfs(row + y[i], col + x[i], grid, current, maxArea);
        }
    }
};