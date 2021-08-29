class Solution {
public:
    int dp[201][201];
    int n,m;
    vector<pair<int,int>> dirs = { {0,-1},{0,1},{1,0},{-1,0} };
    
    int dfs(int i,int j,int val,vector<vector<int>>& matrix) {
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 0;
        for (auto dir : dirs) {
            int x = i + dir.first;
            int y = j + dir.second;
            if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > val) {
                ans = max(ans,dfs(x,y,matrix[x][y],matrix));
            }
        }
        return dp[i][j] = ans + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix[i][j], matrix));
            }
        }
        return ans;
    }
};