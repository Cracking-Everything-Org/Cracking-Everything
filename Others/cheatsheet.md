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

![collection decision tree](https://i.stack.imgur.com/G70oT.png)
