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

    map<char, char> hm;
    hm.insert('E','3');
    hm.insert('3','E');
    hm.insert('2','S');
    hm.insert('J','L');
    hm.insert('L','J');
    hm.insert('5','Z');
    hm.insert('Z','5');

    bool palindrome = true;
    bool mirrored = false;
    bool wrong = false;
    string line;
    while(getline(cin,line,'\n')){
        int j = line.length()-1, i;
        FOR(i,0,(line.length()/2)-1){
            if(line[i] == line[j] && palindrome && !wrong){
                palindrome = true;
            } else if (hm[line[i]] == line[j] && mirrored && !wrong){
                mirrored = true;
                palindrome = false;
            } else {
                wrong = true;
                if(line[i] != 'O' || line[j] != 'O') palindrome = false;
            }
            j--;
        }
        if(!palindrome && !mirrored){
            cout << line << " -- is not a palindrome." ;//-- is not a palindrome.’ if the string is not a palindrome and is not a mirrored string
        } else if(palindrome && !mirrored){
            cout << line << " -- is a regular palindrome." ;//-- is a regular palindrome.’ if the string is a palindrome and is not a mirrored string
        } else if(!palindrome && mirrored){
            cout << line << " -- is a mirrored string." ;//-- is a mirrored string.’ if the string is not a palindrome and is a mirrored string
        } else {
            cout << line << " -- is a mirrored palindrome." ;//-- is a mirrored palindrome.’ if the string is a palindrome and is a mirrored string
        }
        cout << endl;
    }
	return 0;
}