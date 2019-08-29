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

string line;
int result;
char rollPoints; 
bool spareDone;
bool strikeDone1, strikeDone2;

void ex1() {
	while (getline(cin, line, '\n')){
		result = 0;
		int aux1=0, aux2=0;
		spareDone = false;
		strikeDone1 = strikeDone2 = false;
		if(line != "Game Over"){
			int framePart = 1;
			int anterior = 0;
			while (cin >> rollPoints){
				if(rollPoints == '/') { 
					result += 10 - anterior;
					spareDone = true;
				}
				else if (rollPoints == 'X'){
					result += 10;
					strikeDone1 = strikeDone2 = true;
				}
				else {
					result += rollPoints - (int)48;
					anterior = rollPoints - (int)48;
					if(spareDone){
						result += rollPoints - (int)48;
						spareDone = false;
					}
					if(strikeDone1 || strikeDone2){
						if(strikeDone2){
							result += rollPoints - (int)48;
							strikeDone2 = false;
						}else {
							result += rollPoints - (int)48;
							strikeDone1 = false;
						}
					}
				}
			}
			cout << result << endl;
		}
    }
}

int main() {
	ios::sync_with_stdio(false); //Hace el cin/cout + rapido pero no podemos usar prinf/scanf
	cin.tie(NULL); //Desactiva el flush del buffer de cout al realizar un cin
	ex1();
	return 0;
}