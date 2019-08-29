#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
 
using namespace std;
 
#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define MAX 1000000000
#define MIN -1000000000
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<vi> mat;
 
int tc, a, b, c, from, to;
 
void doMov(int playerNum, int dieNum, vi fromTo, vi playerPos) {
    int newPos = playerPos[playerNum]+dieNum;
    playerPos[playerNum] = (fromTo[newPos] > 0)? fromTo[newPos] : newPos;
}
 
int main() {
    cin >> tc;
    while (tc--){
        vi hm;
        cin >> a >> b >> c;
        vi playerPos;
        int i = 0;
        int cantP = a;
        while (a--) {
            playerPos[i] = 1;
            i++;
        }
        while(b--) {
            cin >> from >> to;
            hm[from] = to;
        }
        int round = 1;
        while(c--) {
            if(playerPos[round % cantP] != 100) {
                doMov(round % cantP, c, hm, playerPos);
            }
        }
        FOR(i, 1, cantP) {
            cout << "Position of player " << i << " is " << playerPos[i] << "." << endl;
        }
    }
    return 0;
}