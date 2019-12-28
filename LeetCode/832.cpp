class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); i++) {
            std::reverse(A[i].begin(), A[i].end()); // reverse each row
            for (int j = 0; j < A[i].size(); j++) {
                A[i][j] = A[i][j]^1; // flip the image
            }
        }
        return A;
    }
};
