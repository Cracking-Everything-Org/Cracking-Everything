class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        int EMPTY = INT_MAX;
        int GATE = 0;
        int WALL = -1;

        vector<pair<int,int>> positions;
        positions.push_back(make_pair(-1,0));
        positions.push_back(make_pair(1,0));
        positions.push_back(make_pair(0,-1));
        positions.push_back(make_pair(0,1));

        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == EMPTY) {
                    rooms[i][j] = bfs(i, j, rooms, positions, EMPTY, GATE, WALL);
                }
            }
        }
    }

    int bfs(int i, int j, vector<vector<int>>& rooms,vector<pair<int,int>> positions, int EMPTY, int GATE, int WALL) {

        vector<vector<int>> distances(rooms.size(), vector<int>(rooms[0].size(), 0));
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        while(!q.empty()) {
            int n = q.size();
            for (int x = 0; x < n; x++) {
                pair<int,int> current = q.front();
                q.pop();
                for (auto pos : positions) {
                    int r = current.first + pos.first;
                    int c = current.second + pos.second;
                    if (r < 0 || c < 0 || r >= rooms.size() || c >= rooms[0].size()
                        || rooms[r][c] == WALL || distances[r][c] != 0) {
                        continue;
                    }
                    distances[r][c] = distances[current.first][current.second] + 1;
                    if (rooms[r][c] == GATE) {
                        return distances[r][c];
                    }
                    q.push(make_pair(r,c));
                }
            }
        }
        return INT_MAX;
    }

    // O(m^2 n^2) // para cada punto en el tablero, tengo que hacer m*n pasos
    // O(mn)
};
