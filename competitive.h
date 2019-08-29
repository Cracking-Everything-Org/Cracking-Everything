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

void ex1() {
	fstream mf("../../testFile.txt");
	ofstream rf("../../resultFile.txt");
	if (mf.is_open()) 
	{
		int tc;
		int actual = 1;
		mf >> tc;
		while (tc--) 
		{
			//...
			if (rf.is_open()) 
			{
				if (/*...*/)
					rf << "Caso " << actual << ": " /*<< ... */ ;
				else
					rf << "Caso " << actual << ": " /*<< ... */ ;
				if (tc > 0) rf << endl;
			}
			actual++;
		}
		mf.close(); 
		rf.close();
	}
	else
		cout << "ERROR OPEN FILE";
}

void ex2(){}
void ex3(){}
void ex4(){}
void ex5(){}
void ex6(){}

int main() {
	//ios::sync_with_stdio(false); //Hace el cin/cout + rapido pero no podemos usar prinf/scanf
	//cin.tie(NULL); //Desactiva el flush del buffer de cout al realizar un cin
	// ex1();
	// ex2();
	// ex3();
	// ex4();
	// ex5();
	// ex6();
	//system("pause");
	return 0;
}
