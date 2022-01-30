class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        // dot multiplication, muultiplico cada elemento de la col con el equivalente en la row y voy sumando

        int rows = A.size();
        int cols = B[0].size();

        vector<vector<int>> matrix(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int  j = 0; j < cols; j++) {
                for (int k = 0; k < B.size(); k++) { // puedo cambiar el B.size() por una variable y definirla arriba
                    matrix[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return matrix;

    }
};
