class Solution {
    
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ret = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) 
                    continue;
                
                for (int k = 0; k < 4; k++)
                    dp[i][j][k] = 1;
                
                if (j > 0)
                    dp[i][j][0] += dp[i][j-1][0];
                if (i > 0)
                    dp[i][j][1] += dp[i-1][j][1];
                if (i > 0 && j > 0)
                    dp[i][j][2] += dp[i-1][j-1][2];
                if (i > 0 && j < n-1)
                    dp[i][j][3] += dp[i-1][j+1][3];
                
                ret = max({ ret, dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3] });   
            }
        }
        return ret;
    }
};