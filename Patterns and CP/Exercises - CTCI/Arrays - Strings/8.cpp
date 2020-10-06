#include <vector>
#include <unordered_set>

using namespace std;

void zeroMatrix(vector<vector<int>>& mat){
    unordered_set<int> rows = {};
    unordered_set<int> cols = {};
    for(int i=0; i<mat.size();i++){
        for(int j=0; j<mat.size();j++){
            rows.insert(i);
            cols.insert(j);
        }
    }
    for(int i=0; i<mat.size();i++){
        for(int j=0; j<mat.size();j++){
            if(rows.find(i)!=rows.end()) mat[i][j]=0;    
            else if(cols.find(i)!=cols.end()) mat[i][j]=0;    
        }
    }
}