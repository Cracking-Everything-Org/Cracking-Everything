class TicTacToe {
public:
    /** Initialize your data structure here. */

    vector<int> rowCounter;
    vector<int> colCounter;
    int leftDiag = 0;
    int rightDiag = 0;
    int size;

    TicTacToe(int n) {
        this->rowCounter.resize(n);
        this->colCounter.resize(n);
        this->size = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int move = player == 1 ? 1 : -1;
        rowCounter[row] += move;
        colCounter[col] += move;
        if (row == col) {
            leftDiag += move;
        }
        if (row == size - col - 1) {
            rightDiag += move;
        }
        if (rowCounter[row] == size || colCounter[col] == size || leftDiag == size || rightDiag == size) {
            return 1;
        }
        else if (rowCounter[row] == -size || colCounter[col] == -size || leftDiag == -size || rightDiag == -size) {
            return 2;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
