class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int squares = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        if (!rows || !cols) return squares;
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // initilization of dp[0] and also all 0 are covered
                if (!i || !j || matrix[i][j] == 0) {
                    dp[i][j] = matrix[i][j] ;
                } 
                
                // since all 0 are in the if loop
                // if the min value in all the squares top left right is 1 then add 1 and make it size 2
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                squares += dp[i][j];
            }
        }    
            
        return squares;
    }
};'