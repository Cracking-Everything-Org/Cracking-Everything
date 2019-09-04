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

void ex() {
	fstream r("../../input.txt");
	ofstream w("../../output.txt");
	if (r.is_open())
	{
		int tc;
		int actual = 1;
		r >> tc;
		while (tc--)
		{
			//...
			if (w.is_open())
			{
				if (/*...*/)
					w << "Caso " << actual << ": " /*<< ... */;
				else
					w << "Caso " << actual << ": " /*<< ... */;
				if (tc > 0) w << endl;
			}
			actual++;
		}
		r.close();
		w.close();
	}
	else
		cout << "ERROR OPEN FILE";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ex();

	return 0;
}
