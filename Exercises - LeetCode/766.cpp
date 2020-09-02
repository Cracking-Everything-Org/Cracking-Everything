class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int row = 0; row < matrix.size(); row++) {
            int previous = matrix[row][0];
            int currentCol = 0;
            int currentRow = row;
            while (currentRow < matrix.size() && currentCol < matrix[0].size()) {
                if (matrix[currentRow][currentCol] != previous) {
                    return false;
                }
                currentRow++;
                currentCol++;
            }
        }

        for (int col = 1; col < matrix[0].size(); col++) {
            int previous = matrix[0][col];
            int currentCol = col;
            int currentRow = 0;
            while (currentRow < matrix.size() && currentCol < matrix[0].size()) {
                if (matrix[currentRow][currentCol] != previous) {
                    return false;
                }
                currentRow++;
                currentCol++;
            }
        }

        return true;
    }
};
