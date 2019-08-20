#include <iostream>
#include <vector>

using namespace std;

int n, m, tc = 1;
vector<vector<char> > loaded;

char determine(int row, int col){
    int times = 0;
    for(int i=row-1; i<= row+1; i++){
        for(int j=col-1; j<=col+1; j++){
            if(i>=0 && i<=n && j>=0 && j<=m){
                if(i == 0 && j==0) continue;
                if(loaded[i][j]=='*') times++;
            }
        }
    }
    char c = times;
    return c;
}

int main (){
    string line;

    while(scanf("%d %d", &n, &m), n || m){

        loaded = vector<vector<char> >();
        
        for(int k=0; k<n; k++){
            cin >> line;
            for(int c=0; c<m; c++){
                loaded[k][c]=line[m];
            }
        }

        for(int i=0; i< n; i++){
            for(int j=0; j< m; j++){
                if(loaded[i][j]=='*') cout<< '*';
                else cout << determine(i, j);
                cout << endl;
            }
        }

        tc++;
    }
    return 0;
}