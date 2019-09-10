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

## `unordered_map` (HASH TABLE - avg. time complexity: O(1))

```cpp
#include <unordered_map>  // Include map (std namespace)

unordered_map<string, string> HT;
HT.insert({"asd","asd"});
for(auto it :HT){ // itero sobre las keys
    for(auto str :it.second){ // itero sobre las values
        list.push_back(str);
        it.first; // devuelve la key
        
        unordered_map<string, int> a; // Map from string to int
        a["another"] = 4; // Add or replace element a["hello"]
        a.find("hello");    // 3
        a.size();       // 2
        ```
        
## `unordered_set` (HASH SET - avg. time complexity: O(1))
        
        ```cpp
#include <unordered_set>  // Include set (std namespace)
        
        unordered_set<int> s;     // Set of integers
        s.insert(123);            // Add element to set
        if (s.find(123) != s.end()) // find returns end iterator if key is not found, else it returns iterator to that key
            s.erase(123);
            s.size();         // Number of elements in set
            ```
            
## `map` (associative array - usually implemented as binary search trees - avg. time complexity: O(log n))
            
            ```cpp
#include <map>            // Include map (std namespace)
            
            map<string, int> a;       // Map from string to int
        a["hello"] = 3;           // Add or replace element a["hello"]
        for (auto& p:a)
            cout << p.first << p.second;  // Prints hello, 3
            a.size();                 // 1
            ```
            
## `set` (store unique elements - usually implemented as binary search trees - avg. time complexity: O(log n))
            
            ```cpp
#include <set>            // Include set (std namespace)
            
            set<int> s;               // Set of integers
            s.insert(123);            // Add element to set
            if (s.find(123) != s.end()) // Search for an element
            s.erase(123);
            cout << s.size();         // Number of elements in set
            ```
            
## `string` (Variable sized character array)
            
            ```cpp
#include <string>         // Include string (std namespace)
            
            string s1, s2="hello";    // Create strings
            s1.size(), s2.size();     // Number of characters: 0, 5
            s1 += s2 + ' ' + "world"; // Concatenation
            s1 == "hello world"       // Comparison, also <, >, !=, etc.
            s1[0];                    // 'h'
            s1.substr(m, n);          // Substring of size n starting at s1[m]
            s1.c_str();               // Convert to const char*
            s1 = to_string(12.05);    // Converts number to string
            to_string(123);           // "123"
            getline(cin, s);          // Read line ending in '\n'
            ```
            
## `stack` `vector` `queue` (Variable sized array/stack with built in memory allocation)
            
            ```cpp
#include <stack>
            stack<int> stk;           // empty stack
            stk.push(3);              // {3}
            stk.top();                // 3
            stk.pop();                // { }
            
#include <vector>         // Include vector (std namespace)
            vector<int> a(10);        // a[0]..a[9] are int (default size is 0)
            vector<int> b{1,2,3};        // Create vector with values 1,2,3
            a.size();                 // Number of elements (10)
            swap(a[0],a[1]);
            a.push_back(3);           // Increase size to 11, a[10]=3
            a.back()=4;               // a[10]=4;
            a.pop_back();             // Decrease size by 1
            a.front();                // a[0];
            a[20]=1;                  // Crash: not bounds checked
            a.at(20)=1;               // Like a[20] but throws out_of_range()
            for (int& p : a)
            p=0;                    // C++11: Set all elements of a to 0
            for (vector<int>::iterator p=a.begin(); p!=a.end(); ++p)
            *p=0;                   // C++03: Set all elements of a to 0
            vector<int> b(a.begin(), a.end());  // b is copy of a
            vector<T> c(n, x);        // c[0]..c[n-1] init to x
            T d[10]; vector<T> e(d, d+10);      // e is initialized from d
            a.insert(a.end(), b.begin(), b.end())     // addAll from another vector (b) to vector (a)
            
#include <queue>
            queue<int> q;
            q.push()              // adds to the end of the queue
            q.pop()               // delete the first element
            q.front()             // return the first element
            q.back()              // return the last element
            q.empty()             // return true if que queue has no elements
            q.size()              // return the queue's size
            
            ```
            
## `algorithm` (A collection of algorithms on sequences with iterators)
            
            ```cpp
#include <algorithm>      // Include algorithm (std namespace)
            min(x, y); max(x, y);     // Smaller/larger of x, y (any type defining <)
            swap(x, y);               // Exchange values of variables x and y
            sort(a, a+n);             // Sort array a[0]..a[n-1] by <
            sort(a.begin(), a.end()); // Sort vector or deque
            vector<char> strVector (str.begin(),str.end());
            sort(strVector.begin(), strVector.end());
            string vectorToStr (sVector.begin(),sVector.end());
            reverse(a.begin(), a.end()); // Reverse vector or deque
            INT_MIN
            abs(a);
            
#include <cmath>
            fmax(a,b);
            ```
            
## Reading a text file using an ifstream (input file stream)
            
            - 1 Include the necessary headers.
            ```cpp
#include <fstream>
            using namespace std;
            ```
            - 2 Declare an input file stream (ifstream) variable. For example,
            ```cpp
            ifstream inFile;
            ```
            - 3 Open the file stream. Path names in MS Windows use backslashes (\). Because the backslash is also the string escape character, it must be doubled. If the full path is not given, most systems will look in the directory that contains the object program. For example,
            ```cpp
            inFile.open("C:\\temp\\datafile.txt");
            ```
            - 4 Check that the file was opened. For example, the open fails if the file doesn't exist, or if it can't be read because another program is writing it. A failure can be detected with code like that below using the ! (logical not) operator:
            ```cpp
            if (!inFile) {
                cerr << "Unable to open file datafile.txt";
                exit(1);   // call system to stop
            }
            ```
            - 5 Read from the stream in the same way as cin. For example,
            ```cpp
            while (inFile >> x) {
                sum = sum + x;
            }
            ```
            - 6 Close the input stream. Closing is essential for output streams to be sure all information has been written to the disk, but is also good practice for input streams to release system resources and make the file available for other programs that might need to write it.
            ```cpp
            inFile.close();
            ```
            
## `iostream.h`, `iostream` (Replaces `stdio.h`; `cin`, `cout`)
            
            ```cpp
#include <iostream>         // Include iostream (std namespace)
            cin >> x >> y;              // Read words x and y (any type) from stdin
            cout << "x=" << 3 << endl;  // Write line to stdout
            cerr << x << y << flush;    // Write to stderr and flush
            c = cin.get();              // c = getchar();
            cin.get(c);                 // Read char
            cin.getline(s, n, '\n');    // Read line into char s[n] to '\n' (default)
            if (cin)                    // Good state (not EOF)?
            // To read/write any type T:
            istream& operator>>(istream& i, T& x) {i >> ...; x=...; return i;}
            ostream& operator<<(ostream& o, const T& x) {return o << ...;}
            ```
            
## `fstream.h`, `fstream` (File I/O works like `cin`, `cout` as above)
            
            ```cpp
#include <fstream>          // Include filestream (std namespace)
            ifstream f1("filename");    // Open text file for reading
            if (f1)                     // Test if open and input available
            f1 >> x;                // Read object from file
            f1.get(s);                  // Read char or line
            f1.getline(s, n);           // Read line into string s[n]
            ofstream f2("filename");    // Open file for writing
            if (f2) f2 << x;            // Write to file
            ```
            
## `math.h`, `cmath`, `cstdlib` (floating point math)
            
            ```cpp
#include <cmath>            // Include cmath (std namespace)
            sin(x); cos(x); tan(x);     // Trig functions, x (double) is in radians
            asin(x); acos(x); atan(x);  // Inverses
            atan2(y, x);                // atan(y/x)
            sinh(x); cosh(x); tanh(x);  // Hyperbolic sin, cos, tan functions
            exp(x); log(x); log10(x);   // e to the x, log base e, log base 10
            pow(x, y); sqrt(x);         // x to the y, square root
            ceil(x); floor(x);          // Round up or down (as a double)
            fabs(x); fmod(x, y);        // Absolute value, x mod y
            
#include <cstdlib>
            abs(x);
            ```
            
## `assert.h`, `cassert` (Debugging Aid)
            
            ```cpp
#include <cassert>        // Include iostream (std namespace)
            assert(e);                // If e is false, print message and abort
#define NDEBUG            // (before #include <assert.h>), turn off assert
            ```
            
## `utility` (Pair)
            
            ```cpp
#include <utility>        // Include utility (std namespace)
            pair<string, int> a("hello", 3);  // A 2-element struct
            a.first;                  // "hello"
            a.second;                 // 3
            ```
            
## Expressions
            
            Operators are grouped by precedence, highest first. Unary operators and assignment evaluate right to left. All
            others are left to right. Precedence does not affect order of evaluation, which is undefined. There are no run time
            checks for arrays out of bounds, invalid pointers, etc.
            
            ```cpp
            T::X                        // Name X defined in class T
            N::X                        // Name X defined in namespace N
            ::X                         // Global name X
            
            t.x                         // Member x of struct or class t
            p-> x                       // Member x of struct or class pointed to by p
            a[i]                        // i'th element of array a
            f(x,y)                      // Call to function f with arguments x and y
            T(x,y)                      // Object of class T initialized with x and y
            x++                         // Add 1 to x, evaluates to original x (postfix)
            x--                         // Subtract 1 from x, evaluates to original x
            typeid(x)                   // Type of x
            typeid(T)                   // Equals typeid(x) if x is a T
            dynamic_cast< T>(x)         // Converts x to a T, checked at run time.
            static_cast< T>(x)          // Converts x to a T, not checked
            reinterpret_cast< T>(x)     // Interpret bits of x as a T
            const_cast< T>(x)           // Converts x to same type T but not const
            
            sizeof x                    // Number of bytes used to represent object x
            sizeof(T)                   // Number of bytes to represent type T
            ++x                         // Add 1 to x, evaluates to new value (prefix)
            --x                         // Subtract 1 from x, evaluates to new value
            ~x                          // Bitwise complement of x
            !x                          // true if x is 0, else false (1 or 0 in C)
            -x                          // Unary minus
            +x                          // Unary plus (default)
            &x                          // Address of x
            *p                          // Contents of address p (*&x equals x)
            new T                       // Address of newly allocated T object
            new T(x, y)                 // Address of a T initialized with x, y
            new T[x]                    // Address of allocated n-element array of T
            delete p                    // Destroy and free object at address p
            delete[] p                  // Destroy and free array of objects at p
            (T) x                       // Convert x to T (obsolete, use .._cast<T>(x))
            throw x                     // Throw exception, aborts if not caught
            x , y                       // evaluates x and y, returns y (seldom used)
            ```
            
## Declarations
            
            ```cpp
            int x;                      // Declare x to be an integer (value undefined)
            int x=255;                  // Declare and initialize x to 255
            short s; long l;            // Usually 16 or 32 bit integer (int may be either)
            char c='a';                 // Usually 8 bit character
            unsigned char u=255;
            signed char s=-1;           // char might be either
            unsigned long x =
            0xffffffffL;              // short, int, long are signed
            float f; double d;          // Single or double precision real (never unsigned)
            bool b=true;                // true or false, may also use int (1 or 0)
            int a, b, c;                // Multiple declarations
            int a[10];                  // Array of 10 ints (a[0] through a[9])
            int a[]={0,1,2};            // Initialized array (or a[3]={0,1,2}; )
            int a[2][2]={{1,2},{4,5}};  // Array of array of ints
            char s[]="hello";           // String (6 elements including '\0')
            std::string s = "Hello"     // Creates string object with value "Hello"
            std::string s = R"(Hello
            World)";                    // Creates string object with value "Hello\nWorld"
            int* p;                     // p is a pointer to (address of) int
            char* s="hello";            // s points to unnamed array containing "hello"
            void* p=nullptr;            // Address of untyped memory (nullptr is 0)
            int& r=x;                   // r is a reference to (alias of) int x
            enum weekend {SAT,SUN};     // weekend is a type with values SAT and SUN
            enum weekend day;           // day is a variable of type weekend
            enum weekend{SAT=0,SUN=1};  // Explicit representation as int
            enum {SAT,SUN} day;         // Anonymous enum
            enum class Color {Red,Blue};// Color is a strict type with values Red and Blue
            Color x = Color::Red;       // Assign Color x to red
            typedef String char*;       // String s; means char* s;
            const int c=3;              // Constants must be initialized, cannot assign to
            const int* p=a;             // Contents of p (elements of a) are constant
            int* const p=a;             // p (but not contents) are constant
            const int* const p=a;       // Both p and its contents are constant
            const int& cr=x;            // cr cannot be assigned to change x
            int8_t,uint8_t,int16_t,
            uint16_t,int32_t,uint32_t,
            int64_t,uint64_t            // Fixed length standard types
            auto it = m.begin();        // Declares it to the result of m.begin()
            auto const param = config["param"];
            // Declares it to the const result
            auto& s = singleton::instance();
            // Declares it to a reference of the result
            ```
            
            
            //------------------ Dijkstra ----------------------
            //Algoritmo greedy, no le importa el más optimo sino el más barato.
            //Camino más corto entre un Origen y todos los demas nodos del arbol(Si es que hay camino)
            const int largo = 1; //largo de la tabla
            vector<vector<int>> matriz(largo, vector<int>(largo));
            
            struct NodoD {
                int costo;
                int anterior;
                bool conocido;
            };
            
            void Inicio(vector<NodoD>& res) {
                for (int i = 1; i <= res.size(); i++) {
                    res[i].costo = MIN;
                    res[i].anterior = NULL;
                    res[i].conocido = false;
                }
            }
            
            int verticeNoConocidoMenorCosto(vector<NodoD> resultado) {
                int vMin = 1;
                for (int i = 1; i <= largo; i++) {
                    if (!resultado[i].conocido && resultado[i].costo < resultado[vMin].costo) {
                        vMin = i;
                    }
                }
                return vMin;
            }
            
            void Dijkstra(int origen, vector<vector<int>> tabla) {
                vector<NodoD> resultado = vector<NodoD>(largo);
                Inicio(resultado);
                resultado[origen].costo = 0;
                for (int i = 1; i <= tabla.size(); i++) {
                    int menorVertice = verticeNoConocidoMenorCosto(resultado);
                    resultado[menorVertice].conocido = true;
                    for (int j = 1; j <= tabla.size(); j++) {
                        if (tabla[menorVertice][j] != MIN) {
                            if (!resultado[j].conocido && resultado[j].costo > resultado[menorVertice].costo + tabla[menorVertice][j]) {
                                resultado[j].costo = resultado[menorVertice].costo + matriz[menorVertice][j];
                                resultado[j].anterior = menorVertice;
                            }
                        }
                    }
                }
            }
            
            //------------------ FLOYD ----------------------
            //Camino más corto entre cualquier par de vertices ponderado.
            
            void Floyd(vector<vector<int>> tabla, vector<vector<int>> res) {
                int largo = tabla.size();
                for (int i = 1; i <= largo; i++) { //Inicializacion
                    for (int j = 1; j <= tabla[i].size(); j++) {
                        res[i][j] = tabla[i][j];
                    }
                }
                for (int k = 1; k <= largo; k++) { //Actualizacion
                    for (int i = 1; i <= largo; i++) {
                        for (int j = 1; j <= largo; j++) {
                            res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
                        }
                    }
                }
            }
            
            //------------------ Warshall ----------------------
            //Indica si hay o no camino entre cualquier par de vertices del grafo, nos permite saber si el grafo es conexo.
            void Floyd(vector<vector<bool>> tabla, vector<vector<bool>> res) {
                int largo = tabla.size();
                for (int i = 1; i <= largo; i++) { //Inicializacion
                    for (int j = 1; j <= tabla[i].size(); j++) {
                        res[i][j] = tabla[i][j];
                    }
                }
                for (int k = 1; k <= largo; k++) { //Actualizacion
                    for (int i = 1; i <= largo; i++) {
                        for (int j = 1; j <= largo; j++) {
                            if (res[i][j] > res[i][k] + res[k][j]) {
                                res[i][j] = res[i][k] + res[k][j];
                            }
                        }
                    }
                }
            }
            
            //------------------ Orden Topologico ----------------------
            //Ordenación de vertices para un grafo, en caso de haber ciclos no se puede ordenar.
            const int largo = 2;
            
            
            void Inicio(vector<vector<int>> mat, vector<int> gradoE) {
                for (int i = 1; i <= mat.size(); i++) {
                    for (int j = 1; j <= mat.size(); j++) {
                        gradoE[i] = mat[i][j];
                    }
                }
            }
            
            bool OrdenTopologico(vector<vector<int>> mat) {
                vector<int> gradoE(mat.size(), 0);
                vector<int> res(mat.size(), 0);
                vector<bool> conocido(mat.size(), false);
                Inicio(mat, gradoE);
                for (int i = 1; i <= largo; i++)
                {
                    int vertice = ObtenerGradoEntranteCero(); //Devuelve el primer no conocido con gradoE = 0 o sino -1;
                    if (vertice == -1) {
                        return false;
                    }
                    res[i] = vertice;
                    conocido[i] = true;
                    for (int j = 1; j <= largo; j++) {
                        if (!conocido[j] && mat[j][vertice] == 1) {
                            gradoE[j] --;
                        }
                    }
                }
                return true;
            }
            //------------------ Prim ----------------------
            //Solo sirve para componentes conexas, arbol de cubrimiento minimo.
            
            //------------------ Kruskal ----------------------
            //Bosque de cubrimiento mínimo para grafos no dirigidos.
            
#define V 5
            int parent[V];
            
            // Find set of vertex i
            int find(int i)
        {
            while (parent[i] != i)
                i = parent[i];
            return i;
        }
            
            // Does union of i and j. It returns
            // false if i and j are already in same
            // set.
            void union1(int i, int j)
        {
            int a = find(i);
            int b = find(j);
            parent[a] = b;
        }
            
            // Finds MST using Kruskal's algorithm
            void kruskalMST(int cost[][V])
        {
            int mincost = 0; // Cost of min MST.
            
            // Initialize sets of disjoint sets.
            for (int i = 0; i < V; i++)
                parent[i] = i;
            
            // Include minimum weight edges one by one
            int edge_count = 0;
            while (edge_count < V - 1) {
                int min = INT_MAX, a = -1, b = -1;
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        if (find(i) != find(j) && cost[i][j] < min) {
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
                
                union1(a, b);
                mincost += min;
            }
        }
