#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

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
				if (costoOpt != MAX)
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
		cout << "Unable to open file";
}

void ex2(){}
void ex3(){}
void ex4(){}
void ex5(){}
void ex6(){}

int main() {
	// ex1();
	// ex2();
	// ex3();
	// ex4();
	// ex5();
	// ex6();

	//system("pause");
	return 0;
}
