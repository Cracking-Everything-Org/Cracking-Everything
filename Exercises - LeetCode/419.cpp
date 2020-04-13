class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ships = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X') {
                    ships++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    while (!q.empty()) {
                        pair<int,int> current = q.front();
                        q.pop();
                        board[current.first][current.second] = 'Y';

                        if (current.first - 1 >= 0 && current.first - 1 < board.size() && board[current.first - 1][current.second] == 'X')
                            q.push(make_pair(current.first - 1, current.second));

                        if (current.first + 1 >= 0 && current.first + 1 < board.size() && board[current.first + 1][current.second] == 'X')
                            q.push(make_pair(current.first + 1, current.second));

                        if (current.second >= 0 && current.second - 1 < board[0].size() && board[current.first][current.second - 1] == 'X')
                            q.push(make_pair(current.first, current.second - 1));

                        if (current.second >= 0 && current.second + 1 < board[0].size() && board[current.first][current.second + 1] == 'X')
                            q.push(make_pair(current.first, current.second + 1));
                    }
                }
            }
        }
        return ships;
    }
};
