class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for (int cur = 0; cur < n; cur++) {
            int i, j = cur;
            for (i = 0; i < m; i++) {
                if (grid[i][j] == 1) {
                    j++;
                    if (j < n && grid[i][j] == -1) {
                        ans[cur] = -1;
                        break;
                    }
                } else if (grid[i][j] == -1) {
                    j--;
                    if (j >= 0 && grid[i][j] == 1) {
                        ans[cur] = -1;
                        break;
                    }
                }
                if (j < 0 || j >= n) {
                    ans[cur] = -1;
                    break;
                }
            }
            if (i == m)
                ans[cur] = j;
        }
        return ans;
    }
};