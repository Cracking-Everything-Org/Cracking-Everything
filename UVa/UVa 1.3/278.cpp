#include <iostream>
using namespace std;

int main (){

    int tc, rows, cols;
    char piece;
    cin >> tc;
    int num;
    while(tc--){
        cin >> piece >> rows >> cols;
        if(piece == 'r') num = min(rows,cols);
        else if(piece == 'k') num = (rows*cols)/2;
        else if(piece == 'Q') num = min(rows,cols);
        else if(piece == 'K') num = int((cols+1)/2 * (rows+1)/2);
        cout << num << endl;
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int rows, cols;

// bool checkKnight(vector<vector<bool> > board, int row, int col){
//     // la reputa madre, era con forma cerrada.
// }

// bool checkQueen(vector<vector<bool> > board, int row, int col){
//     for (int i=0; i<rows; i++){
//         for(int j=0; j<cols; j++){
//             if(abs(rows-row)==abs(cols-col)){
//                 if(board[i][j]) return false;
//             } 
//         }
//     }
//     return false;
// }

// bool checkKing(vector<vector<bool> > board, int row, int col){
//     for(int i=row-1; i<=row+1; i++){
//         for(int j=col-1; j<=col+1; j++){
//             if(i>=0 && i<= rows-1 && j>=0 && j <= cols){
//                 return board[i][j] ? false : true;
//             }
//         }
//     }
// }

// bool checkRook (vector<vector<bool> > board, int row, int col){
//     for(int i=0; i<col ; i++){
//         if(board[row][i]) return false;
//     }
//     for(int j=0; j<row ; j++){
//         if(board[j][col]) return false;
//     }
//     return true;
// }

// bool valid(char piece, int row,  int col, vector<vector<bool> > board){
//     if (piece == 'r'){
//         if(checkRook(board, row, col)) return true;
//     } else if (piece == 'k') {
//         if(checkKnight(board, row, col)) return true;
//     } else if (piece == 'Q') {
//         if(checkQueen(board, row, col)) return true;
//     } else if (piece == 'K') {
//         if(checkKing(board, row, col)) return true;
//     }
//     return false;
// }

// int posibilities (char piece, int rows, int cols, vector<vector<bool> > board){
//     int result = 0;
//     for(int i = 0; i<rows ; i++){
//         for(int j =0; j<cols ; j++){
//             if(valid(piece,i,j, board)){
//                 board[i][j] = true;
//                 result ++;
//             }
//         }
//     }
//     return result;
// }

// int main (){
//     int tc, posibilit;
//     char piece;
//     vector<vector<bool> > board;
//     cin >> tc;
//     while(tc--){
//         cin >> piece >> rows >> cols;
//         posibilit = posibilities(piece, rows, cols, board);
//         cout << posibilit << endl;
//     }
//     return 0;
// }



