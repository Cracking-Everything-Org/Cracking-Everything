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
    string str;
    vector<string> vs;
    unordered_map<string, int> ht;
    unordered_map<string,string> relation;
    while(cin >> str, str != "#"){
        string destinationString;
        destinationString.resize(str.size());
        transform(str.begin(),
        str.end(),
        destinationString.begin(),
        ::tolower);
        vs.push_back(destinationString);
        relation.insert(destinationString,str);
    }
    sort(vs.begin(), vs.end());
    for(int i=0;i<vs.size();i++){
        if(ht.find(vs[i]) == ht.end()) ht[vs[i]] = 1;
        else ht[vs[i]]++;
    }
    for(auto it : ht){
        if(it.second > 1) cout << relation[it.first] << endl;
    }
    
	return 0;
}
