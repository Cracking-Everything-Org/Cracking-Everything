class Solution {
public:
    vector<int> xi = { -1, 0 , 0, 1 };
    vector<int> yi = { 0, 1, -1, 0 };
    
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int islands = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return islands;
    }
    
    void dfs(int row, int col, vector<vector<char>>& grid) {
        grid[row][col] = '2';
        for (int i = 0; i < 4; i++) {
            if (row + xi[i] >= 0 && row + xi[i] < grid.size() && col + yi[i] >= 0 && col + yi[i] < grid[0].size()) {
                if (grid[row + xi[i]][col + yi[i]] == '1') {
                    dfs(row + xi[i], col + yi[i], grid);
                }
            }
        }
    }
};