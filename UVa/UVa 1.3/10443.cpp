#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define MAX 1000000000
#define MIN -1000000000
#define endl "\n"

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<vi> mat;


mat table;

bool isNear(char E, int i, int j){
    int x,z;
    FOR(x,-1,1){
        FOR(z,-1,1){
            if(x != i && j != z && (x==i || z==j)){
                if(table[x][z] == E) return true;
            }
        }
    }
    return false;
}

void doBattle(mat table){
    mat newTable;
    int i, j;
    FOR(i,0,table.size()-1){
        FOR(j,0,table[0].size()-1){
            if(table[i][j] == 'R'){
                newTable[i][j] = isNear('P', i, j)? 'P' : 'R';
            }
            else if(table[i][j] == 'S') {
                newTable[i][j] = isNear('R', i, j)? 'R' : 'S';
            }
            else {
                newTable[i][j] = isNear('S', i ,j)? 'S' : 'P';
            }
        }
    }
    table = newTable;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--){
        int r, c, n;
        cin >> r >> c >> n;
        int i, j;
        FOR(i,0,r-1){
            char movement;
            FOR(j,0,c-1){
                cin >> movement;
                table[i][j] = movement;
            }
        }
        while(n--){
            doBattle(table);
        }
        int x, z;
        FOR(x, 0, r-1){
            FOR(z, 0, c-1){
                cout << table[x][z];
            }
            cout << endl;
        }
    }
	return 0;
}