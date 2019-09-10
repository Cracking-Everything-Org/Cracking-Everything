```cpp
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

void readNoSplit() {
    fstream mf("../../testFile.txt");
    ofstream rf("../../resultFile.txt");
    if (mf.is_open()) {
        int tc;
        int actual = 1;
        mf >> tc;
        while (tc--) {
            //...
            if (rf.is_open()){
                if (/*...*/) {
                    rf << "Caso " << actual << ": " /*<< ... */ ;
                } else {
                    rf << "Caso " << actual << ": " /*<< ... */ ;
                }
                if (tc > 0) rf << endl;
            }
            actual++;
        }
        mf.close();
        rf.close();
    }
    else cout << "ERROR OPEN FILE";
}

void readSplit() {
    string line;
    fstream myfile("../../file.txt");
    vector<int> numbers;
    int currentLine = 1;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << "Line " << currentLine << endl;
            string current;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ' ') {
                    numbers.push_back(atoi(current.c_str()));
                    cout << atoi(current.c_str()) << endl;
                    current = "";
                } else if (line.length() == (i + 1)) {
                    current += line[i];
                    numbers.push_back(atoi(current.c_str()));
                    cout << atoi(current.c_str()) << endl;
                    current = "";
                } else {
                    current += line[i];
                }
            }
            currentLine++;
        }
        myfile.close();
    }
}

void ex1(){}
void ex2(){}
void ex3(){}
void ex4(){}
void ex5(){}
void ex6(){}

int main() {
    ios::sync_with_stdio(false); //Hace el cin/cout + rapido pero no podemos usar prinf/scanf
    cin.tie(NULL); //Desactiva el flush del buffer de cout al realizar un cin
    // ex1();
    // ex2();
    // ex3();
    // ex4();
    // ex5();
    // ex6();
    //system("pause");
    return 0;
}
```

## `vector`
```cpp
v.insert(v.begin(), value);             // Insert head
v.insert(v.begin() + index, value);     // Insert index
v.push_back(value);                     // Insert tail

int head = v.front();       // Access head
int value = v.at(index);    // Access index
int tail = v.back();        // Access tail

for(iterator it = v.begin(); it != v.end(); it++) {     // Iterate
    cout << *it << std::endl;
}

v.erase(v.begin());                                                 // Remove head
v.erase(v.begin() + index);                                         // Remove index
v.pop_back();                                                       // Remove tail
v.clear();                                                          // Clear
```

## `deque`
```cpp
d.push_front(value);                    // Insert head
d.insert(d.begin() + index, value);     // Insert index
d.push_back(value);                     // Insert tail

d.pop_front();                  // Remove head
d.erase(d.begin() + index);     // Remove index
d.pop_back();                   // Remove tail
```

## `map` `unordered_map`
```cpp
string value = m.at("key");                                              // Access by key

for(std::map<int>::iterator it = m.begin(); it != m.end(); it++) {       // Iterate
    std::cout << *it << std::endl;
}

for(auto it :HT){                                                        // itero sobre las keys
    for(auto str :it.second){                                            // itero sobre las values
        list.push_back(str);
it.first;                                                                // IT - the key value (of type Key)
it.second;                                                               // IT - the mapped value (of type T)
it;                                                                      // IT - the pair<const Key,T>

for ( auto it = mymap.begin(); it != mymap.end(); ++it )
    std::cout << " " << it->first << ":" << it->second;

bool exists = (m.find("key") != m.end());                                // FIND if an element exists by key
unsigned int count = m.count("key");                                     // COUNT by key
first.swap(second);                                                      // SWAP
```

## `set` `unordered_set`
```cpp
for(std::set<int>::iterator it = s.begin(); it != s.end(); it++)         // Iterate
    std::cout << *it << std::endl;
    
for ( auto it = myset.begin(); it != myset.end(); ++it )  
    std::cout << " " << *it;

bool exists = (s.find(20) != s.end());                                   // FIND if an element exists
unsigned int count = s.count(20);                                        // COUNT
first.swap(second);                                                      // SWAP
```

## `stack`
```cpp
s.push(20);                                                              // Push
s.pop();                                                                 // Pop
int top = s.top();                                                       // Top
```

## `queue`
```cpp
q.push(value);                                                           // Insert
int head = q.front();                                                    // Access head
int tail = q.back();                                                     // Access tail         
q.pop();                                                                 // Remove
```

## `priority_queue`
```cpp
p.push(value);                                                           // Insert
int top = p.top();                                                       // Access 'Top' element
p.pop();                                                                 // Remove
```

## `algorithm` (A collection of algorithms on sequences with iterators)
```cpp
min(x, y); max(x, y);     // Smaller/larger of x, y (any type defining <)
swap(x, y);               // Exchange values of variables x and y
sort(a, a+n);             // Sort array a[0]..a[n-1] by <
sort(a.begin(), a.end()); // Sort vector or deque
vector<char> strVector (str.begin(),str.end());
sort(strVector.begin(), strVector.end());
string vectorToStr (sVector.begin(),sVector.end());
reverse(a.begin(), a.end()); // Reverse vector or deque
INT_MIN
```

## `math.h`, `cmath`, `cstdlib` (floating point math)
```cpp
sin(x); cos(x); tan(x);     // Trig functions, x (double) is in radians
asin(x); acos(x); atan(x);  // Inverses
atan2(y, x);                // atan(y/x)
sinh(x); cosh(x); tanh(x);  // Hyperbolic sin, cos, tan functions
exp(x); log(x); log10(x);   // e to the x, log base e, log base 10
pow(x, y); sqrt(x);         // x to the y, square root
ceil(x); floor(x);          // Round up or down (as a double)
fabs(x); fmod(x, y);        // Absolute value, x mod y
abs(a);
fmax(a,b);
```

## GEOMETRIA - INTERSECCION  
```cpp            
struct Point {
     int x;
     int y;
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}
            
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

    // The main function that returns true if line segment 'p1q1'
    // and 'p2q2' intersect.
    bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4) return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}         
```
