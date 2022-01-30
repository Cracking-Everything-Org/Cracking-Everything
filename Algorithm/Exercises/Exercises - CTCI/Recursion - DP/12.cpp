using namespace std;
#include <vector>
#include <algorithm>

int GRID_SIZE = 8;

void placeQueens(int row, vector<int> columns, vector<vector<int>> results){
    if(row == GRID_SIZE) results.push_back(columns);
    else {
        for(int col=0; col<GRID_SIZE; col++){
            if(checkValid(columns, row, col)){
                columns[row] = col;
                placeQueens(row+1, columns, results);
            }
        }
    }
}

bool checkValid(vector<int> columns, int actualRow, int actualCol){
    for(int row2 = 0; row2 < actualRow; row2++){
        int column2 = columns[row2];
        if(column2==actualCol) return false;
        int rowDistance = actualRow - row2;
        int colDistance = abs(actualCol-column2);
        if(rowDistance == colDistance) return false;
    }
}