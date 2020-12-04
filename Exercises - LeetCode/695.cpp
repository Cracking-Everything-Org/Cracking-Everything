class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    int currentArea = 0;
                    dfs(grid, row, col, currentArea, maxArea);
                }
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int& currentArea, int& maxArea) {
        if (row < 0 || row > grid.size() - 1 || col < 0 || col > grid[0].size() - 1 || grid[row][col] == 0) {
            return;
        }
        else {
            currentArea++;
            grid[row][col] = 0;
            dfs(grid, row + 1, col, currentArea, maxArea);
            dfs(grid, row - 1, col, currentArea, maxArea);
            dfs(grid, row, col + 1, currentArea, maxArea);
            dfs(grid, row, col - 1, currentArea, maxArea);
            maxArea = currentArea > maxArea ? currentArea : maxArea;
        }
    }
};