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
    string line;
    while((getline(cin, line, '\n')), line != "DONE"){
        string word;
        int i;
        FOR(i, 0, line.length()){
            if(line[i]!='.' && line[i]!=',' && line[i]!='!' && line[i]!='?' && line[i]!=' '){
                word+=line[i];
            }
        }
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        int k = word.length()-1, j;
        bool palindrome = true;
        FOR(j,0,(word.length()/2)-1){
            if(word[i] != word[j]) palindrome = false;
        }
        if(palindrome) cout << "You won’t be eaten!" << endl;
        else cout << "Uh oh.." << endl;
    }
	return 0;
}