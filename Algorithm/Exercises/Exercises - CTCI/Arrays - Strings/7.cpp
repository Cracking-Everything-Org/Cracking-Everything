#include <iostream>
#include <string>
using namespace std;

bool rotateMatrix(int mat[][]){
    if(mat.length == 0 || mat[0].length != mat.length) return false;
    for(int layer = 0; layer < mat.length/2; layer++){
        int first = layer;
        int last = mat.length-1-layer;
        for(int i =first;i<layer;i++){
            int offset = i-first;
            int top = mat[first][i]; //top
            //left -> top
            mat[first][i] = mat[last-offset][first];
            //bottom -> left
            mat[last-offset][first] = mat[last][last-offset];
            //right -> bottom
            mat[last][last-offset] = mat[i][last];
            //top -> right
            mat[i][last] = top;
        }
    }
    return true;
}