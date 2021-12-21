class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                if (matrix[row][col] == 0) {
                    q.push(make_pair(row, col));
                }
            }
        }
        
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            
            for (int row = 0; row < matrix.size(); row++) {
                matrix[row][current.second] = 0;
            }
            
            for (int col = 0; col < matrix[0].size(); col++) {
                matrix[current.first][col] = 0;
            }
        }
    }
};