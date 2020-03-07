#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(int n, int m){
    if(n > m) swap(n,m);
    if(n == 1) return m;
    if(n == 2) return m / 4 * 4 + (m % 4 == 1? 2 : (m % 4 >= 2? 4 : 0));
    return (n*m + 1) / 2;
}

int main (){
    int rows, cols;
    while(scanf("%d %d", &rows, &cols), rows || cols){
        cout << solve(rows,cols) << " knights may be placed on a "<< rows <<" row "<< cols<<" column board." << endl;
    }
    return 0;
}