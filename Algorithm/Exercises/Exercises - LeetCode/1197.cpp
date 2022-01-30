class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;

        vector<pair<int, int>> steps =
        {
            {2, 1},
            {1, 2},
            {-1, 2},
            {-2, 1},
            {-2, -1},
            {-1, -2},
            {1, -2},
            {2, -1},
        };

        unordered_map<int, unordered_map<int, bool>> visited;
        queue<pair<int, int>> Q;
        Q.push(make_pair(0, 0));
        visited[0][0] = true;

        int moves = 0;

        while (!Q.empty()) {
            moves++;
            int len = Q.size();
            for (size_t i = 0; i < len; i++) {
                auto curr = Q.front();
                Q.pop();

                for (const auto& step : steps) {
                    int nextX = curr.first + step.first;
                    int nextY = curr.second + step.second;

                    if (nextX == x && nextY == y) {
                        return moves;
                    }

                        if(!visited[nextX][nextY] && nextX * x >= -2 && nextY * y >= -2) {
                        visited[nextX][nextY] = true;
                        Q.push(make_pair(nextX, nextY));
                    }
                }
            }
        }

        return -1;
    }
};
