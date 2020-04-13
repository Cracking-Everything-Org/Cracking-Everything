class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    for (int a = 0; a < matrix.size(); a++) {
                        if (matrix[a][j] != 0) matrix[a][j] = -1000000;
                    }
                    for (int b = 0; b < matrix[0].size(); b++) {
                        if (matrix[i][b] != 0) matrix[i][b] = -1000000;
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == -1000000) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
