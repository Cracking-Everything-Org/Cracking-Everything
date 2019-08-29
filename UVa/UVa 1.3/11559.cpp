#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main () {
    int n, b, h, w, hCost, hRooms, best;
    while(scanf("%d %d %d %d\n", &n, &b, &h, &w) != EOF){
        best = 5000001;
        while(h--){
            cin >> hCost;
            for(int i=0;i<w;i++) {
                cin >> hRooms;
                if(hRooms >= n){
                    best = min(best, hCost*n);
                }
            }
        }
        if(best <= b) cout << best << endl;
        else cout << "stay home" << endl;
    }
    return 0;
}

