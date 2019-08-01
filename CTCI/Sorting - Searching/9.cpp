using namespace std;
#include <iostream> 
#include <string>
#include <vector>

bool findElement(vector<vector<int>> matrix, int elem){
    int row=0;
    int col=matrix[0].size()-1;
    while(row< matrix.size() && col >= 0){
        if(matrix[row][col] == elem) return true;
        else if(matrix[row][col] > elem) col--;
        else row++;
    }
    return false;
}