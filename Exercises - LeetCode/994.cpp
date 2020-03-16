class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;

        queue<pair<int, int>> q;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i,j));
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                pair<int,int> c = q.front();
                q.pop();
                grid[c.first][c.second] = 2;
                if (c.first-1 > 0) { q.push(make_pair(c.first-1, c.second)); }
                if (c.first+1 < grid.size()) { q.push(make_pair(c.first+1, c.second)); }
                if (c.second-1 > 0) { q.push(make_pair(c.first, c.second-1)); }
                if (c.second+1 < grid[0].size()) { q.push(make_pair(c.first, c.second+1)); }

            }
            minutes++;
        }

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minutes;


    }
};
