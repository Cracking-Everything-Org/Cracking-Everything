class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        vector<vector<int>> positions = {
            {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
        };
        int m = board.size()-1;
        int n = board[0].size()-1;

        queue<vector<int>> q;
        q.push(click);
        while (!q.empty()) {
            vector<int> current = q.front();
            q.pop();
            if (board[current[0]][current[1]] == 'M') {
                board[current[0]][current[1]] = 'X';
            } else {
                int minesAround = countMines(current, board, positions);
                if (board[current[0]][current[1]] == 'E' && minesAround == 0) {
                    board[current[0]][current[1]] = 'B';
                    for (auto pos : positions) {
                        int row = current[0] + pos[0];
                        int col = current[1] + pos[1];
                        if (row >= 0 && row <= m && col >= 0 && col <= n && board[row][col] == 'E') {
                            vector<int> toPush = {row, col};
                            q.push(toPush);
                        }
                    }
                } else {
                    board[current[0]][current[1]] = minesAround > 0 ? to_string(minesAround)[0] : 'B';
                }
            }
        }

        return board;
    }

    int countMines(vector<int> current, vector<vector<char>> board, vector<vector<int>> positions) {
        int m = board.size()-1;
        int n = board[0].size()-1;

        int mines = 0;
        for (auto pos : positions) {
           int row = current[0] + pos[0];
           int col = current[1] + pos[1];
           if (row >= 0 && row <= m && col >= 0 && col <= n && board[row][col] == 'M') {
               mines++;
           }
        }
        return mines;
    }
};
