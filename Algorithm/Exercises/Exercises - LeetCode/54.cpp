class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) return result;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        int size = matrix.size() * matrix[0].size();
        while (result.size() < size) {
            for (int i = left; i <= right && result.size() < size; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom && result.size() < size; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            for (int i = right; i >= left && result.size() < size; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            for (int i = bottom; i >= top && result.size() < size; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};
