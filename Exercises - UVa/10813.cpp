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


bool hasNum (int entry){
    if(entry >= 1 && entry <= 15){
        
    } else if(entry >= 16 && entry <= 30){

    } else if(entry >= 31 && entry <= 45){
        // si no cae, marco con -1 el centro 
    } else if(entry >= 46 && entry <= 60){

    } else if(entry >= 61 && entry <= 75){

    }

}

void change (mat table, int entry){
    // cambio por -1 para señalar que tengo
}

void verifyBingo(int rounds, mat table){
    // me fijo vertical, horizontal y diagonal.
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--){
        mat table;
        int i,j;
        FOR(i,0,5){
            FOR(j,0,5){
                if(i==2 && j==2) table[i][j] = 0;
                else{
                    cin >> table[i][j];
                }
            }
        }
        int x,z;
        ll rounds = MAX;
        FOR(x,0,75){
            int entry;
            cin >> entry;
            if(hasNum(entry)){
                change(table, entry);
                verifyBingo(rounds, table);
            }
        }
        cout << "BINGO after " << rounds << "numbers announced" << endl;
    }
	return 0;
}