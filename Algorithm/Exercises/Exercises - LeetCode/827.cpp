#include <algorithm>    // std::max
class Solution {
public:
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    int largestIsland(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int max = 0;
        int islandId = 2;
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, int> hm;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = getIslandSize(grid, i, j, islandId);
                    max = std::max(max, size);
                    hm[islandId++] = size;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> visited;
                    for (vector<int> direction : dirs) {
                        int x = direction[0] + i;
                        int y = direction[1] + j;
                        if (x > - 1 && y > - 1 && x < m && y < n && grid[x][y] != 0) {
                            visited.insert(grid[x][y]);
                        }
                    }
                    int sum = 1;
                    for (int num : visited) {
                        sum += hm[num];
                        visited.erase(num);
                    }
                    
                    max = std::max(max, sum);
                }
            }
        }
        return max;
    }
    
    int getIslandSize(vector<vector<int>>& grid, int i, int j, int islandId) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return 0;
        grid[i][j] = islandId;
        int left = getIslandSize(grid, i, j - 1, islandId);
        int right = getIslandSize(grid, i, j + 1, islandId);
        int up = getIslandSize(grid, i - 1, j, islandId);
        int down = getIslandSize(grid, i + 1, j, islandId);
        return 1 + left + right + up + down;
    }
};