class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0) return {};
        int N = matrix[0].size();

        vector<int> res;
        int r = 0;
        int c = 0;
        int direction  = 1; // 1 hacia arriba, -1 hacia abajo
        while (res.size() < M*N) {
            res.push_back(matrix[r][c]);
            int rNext = r - direction;
            int cNext = c + direction;
            bool outOfBounds = (rNext < 0 || rNext == M || cNext < 0 || cNext == N);
            if (outOfBounds) {
                if (direction == 1) {
                    if (cNext == N) r++;
                    else c++;
                } else {
                    if (rNext == M) c++;
                    else r++;
                }
                direction = -direction; // invierto la direcion
            } else {
                r = rNext;
                c = cNext;
            }
        }
        return res;

    }
};
