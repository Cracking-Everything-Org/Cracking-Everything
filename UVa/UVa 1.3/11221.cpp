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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int tc;
    cin >> tc;
    int num = 1;
    while(tc--){
        string line;
        getline(cin, line);

        int k;
        string str;
        FOR(k,0,line.length()){
            if(line[k] != ' ' && line[k] != ',' 
            && line[k] != '-' && line[k] != '?' 
            && line[k] != '!' && line[k] != '.' 
            && line[k] != '(' && line[k] != ')'){
                str+=line[k];
            }
        }
        int i, j = str.length()-1;
        bool palindrome = true;
        FOR(i, 0, (str.length()/2)-1){
            if(line[i] != line[j]) palindrome = false;
        }
        bool rightSize = false;
        if(sqrt(line.length())* sqrt(line.length()) == line.length()) rightSize = true;
        if(palindrome && rightSize){
            cout <<  "Case #" << num << ":" << endl;
            cout << sqrt(line.length()) << endl;
        } else {
            cout <<  "Case #" << num << ":" << endl;
            cout << "No magic :(" << endl;
        }
        num ++;
    }
	return 0;
}