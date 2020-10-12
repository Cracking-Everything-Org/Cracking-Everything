```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define MOD 1000000007
#define endl "\n"
typedef long long ll;

int main() {
	fastio;
	int T;",
	cin >> T;",
	while(T-- > 0) {
		
	}
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
## GENERICS - ALGO2  
```cpp   
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
	for (int i = 1; i <= largo; i++) {
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
int find(int i){
	while (parent[i] != i)
		i = parent[i];
	return i;
}

// Does union of i and j. It returns
// false if i and j are already in same
// set.
void union1(int i, int j){
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][V]){
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
```

## Lowest Common Ancestor  (recibe un árbol-grafo)
```cpp  
class LCA {
    vector<vector<int>> P;
    graph g; int n, m;

    void build(int u, int p=-1, int lv=0) {
        parent[u] = p;
        level[u] = lv;
        for (int v : g[u]) if (v != p)
            build(v, u, lv+1);
    }

public:
    vector<int> parent, level;

    LCA(graph &gg, int root) {
        g = gg;
        n = g.size();
        parent.resize(n);
        level.resize(n);
        build(root);

        P.assign(n, vector<int>(m=log2(n*2), -1));
        rep(i, n) P[i][0] = parent[i];
        rep(j, m-1) rep(i, n) if (P[i][j] != -1)
            P[i][j+1] = P[ P[i][j] ][j];
    }

    int operator()(int u, int v) {
        if (level[u] < level[v]) swap(u, v);
        int i=0, x; for (; x=level[u]-level[v]; ++i)
            if (x & 1<<i) u = P[u][i];
        if (u == v) return u;
        for (++i; i>=0; --i)
            if (P[u][i] != -1 and P[u][i] != P[v][i])
                u = P[u][i], v = P[v][i];
        return parent[u];
    }
};
```
## Union Find  
```cpp  
Union Find
class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
	setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
	p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {  
	if (!isSameSet(i, j)) { numSets--;  
	int x = findSet(i), y = findSet(j);
	// rank is used to keep the tree short
	if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
	else               	{ p[x] = y; setSize[y] += setSize[x];
                         	if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
```
## BFS  
```cpp  
//BFS O(V+E) = O(V^2)
//vector<int> dist(n,1e9);
void bfs(graph &g, int start, vector<int> &dist) {
    int inf = 1e9;
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) if (dist[v] == inf) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```
## DIJKSTRA
```cpp  
Dijkstra //graph es vector<par> con pares (vecino, peso)
//vector<int> dist(n,1e9);
void dijkstra(wgraph &g, int start, vector<int> &dist) {
    priority_queue<par, vector<par>, greater<par>> q;
    q.push({0, start});
    dist[start] = 0;
    while (not q.empty()) {
        int priority = q.top().first, u = q.top().second;
        q.pop();
        if (priority != dist[u])
            continue;
        for (par p : g[u]) {
            int v = p.first, w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
}
```
## TOPOSORT  
```cpp  
//función auxiliar requerida
void dfs_ts(graph& g, int u, vector<bool>& vis, vector<int>& ts) {
    vis[u] = true;
    for (int v : g[u]) if (not vis[v])
        dfs_ts(g, v, vis, ts);
    ts.pb(u);
}
//ts parte vacío y termina con el toposort
void toposort(graph& g, vector<int>& ts) {
    int n = g.size();
    vector<bool> vis(n, false);
    rep(u, n) if (not vis[u])
        dfs_ts(g, u, vis, ts);
    reverse(ts.begin(), ts.end());
}
```
## FLOYD WARSHALL  
```cpp  
//dist[i][j] contiene inicialmente el peso de la arista (i, j) o 1e9 si no existe esa arista
//el loop es k -> i -> j !!
rep(k, nGrafo) rep(i, nGrafo) rep(j, nGrafo)
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//variante: transitive closure
connected[i][j] es true ssi existe la arista (i, j)
cambiar última línea por: connected[i][j] |= connected[i][k] & connected[k][j];
```
## BELLMAN FORD  
```cpp  
vector<int> dist(nGrafo, 1e9); dist[start] = 0;
rep(i, nGrafo-1) rep(u, nGrafo) for (par p : g[u]) {
    int v = p.first, w = p.second;
    dist[v] = min(dist[v], dist[u] + w);
}
//después de ejecutar lo anterior
bool hayCicloNegativo = false;
rep(u, nGrafo) for (par p: g[u]) {
    int v = p.first, w = p.second;
    if (dist[v] > dist[u] + w)
        hayCicloNegativo = true;
}
```
## PRIM  
```cpp
struct edge {
	int u,v; ll w;
	edge(int u, int v, ll w) : u(u), v(v), w(w) {}

	bool operator< (const edge &o) const{
		return w < o.w;
	}
};
```
## UNION FIND  
```cpp  
struct UnionFind{
	vector<int> P,rank;

	UnionFind(int N){
		P.resize(N); for(int i = 0; i < N; ++i) P[i] = i;
		rank.assign(N,0);
	}

	int findSet(int u){
		return u == P[u] ? u : P[u] = findSet(P[u]);
	}

	bool isSameSet(int u, int v){
		return findSet(u) == findSet(v);
	}

	void joinSets(int u, int v){
		if(isSameSet(u,v)) return;
		u = findSet(u); v = findSet(v);

		if(rank[u] < rank[v]) P[u] = v;
		else{
			P[v] = u;
			if(rank[u] == rank[v]) ++rank[u];
		}
	}
};
int main(){
	vector<edge> E;
	UnionFind U(N);
	sort(E.begin(),E.end());

	for(edge &e : E){
		int u = e.u, v = e.v;
		if(!U.isSameSet(u,v)){
			U.joinSets(u,v);
			//USAR ARISTA
		}
	}
}
```
## GEOMETRIA - INTERSECCION  2 SEGMENTOS
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
## GEOMETRIA - POINT LIES ON SEGMENT
```cpp
const float EPSILON = 0.001f;
bool IsPointOnLine(Point linePointA, Point linePointB, Point point)
{
   float a = (linePointB.y - linePointA.y) / (linePointB.x - linePointB.x);
   float b = linePointA.y - a * linePointA.x;
   if ( fabs(point.y - (a*point.x+b)) < EPSILON)
   {
       return true;
   }

   return false;
}
```
## GEOMETRIA - DISTANCE
```cpp
void getLine(double x1, double y1, double x2, double y2, double &a, double &b, double &c)
{
    // (x- p1X) / (p2X - p1X) = (y - p1Y) / (p2Y - p1Y)
    a = y1 - y2; // Note: this was incorrectly "y2 - y1" in the original answer
    b = x2 - x1;
    c = x1 * y2 - x2 * y1;
}

double dist(double pct1X, double pct1Y, double pct2X, double pct2Y, double pct3X, double pct3Y)
{
    double a, b, c;
    getLine(pct2X, pct2Y, pct3X, pct3Y, a, b, c);
    return abs(a * pct1X + b * pct1Y + c) / sqrt(a * a + b * b);
}
```
## CONVEX HULL  
```cpp  
//(funciona si los puntos son colineales) (se asume que los puntos no se repiten)
//(los casos con menos de 3 puntos deben ser definidos aparte)
typedef double compt; //componente de un punto, podría ser int
struct point {
    compt x, y;
    point(compt xx, compt yy) {x = xx; y = yy;}
    bool operator<(point const o) const {return make_pair(x, y) < make_pair(o.x, o.y);}
};
//asegúrate de que copiaste bien esta función
compt cross(point o, point a, point b) {
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
//recibe “ch” vacío para dejar la convex hull en “ch”
void convex_hull(vector<point> &p, vector<point> &ch) {
    sort(p.begin(), p.end());
    vector<point> L, U;
    int n = p.size();
    #define tmp(x) {\
        while (x.size() >= 2 and cross(x[x.size()-2], x.back(), p[i]) <= 0)\
            x.pop_back(); x.pb(p[i]); }
    rep(i, n) tmp(L) invrep(i, n) tmp(U)
    #undef tmp
    rep(i, L.size()-1) ch.pb(L[i]);
    rep(i, U.size()-1) ch.pb(U[i]);
}
```
## Potencia de 2 mas cercana  
```cpp  
//(con x<2 ambas retornan 1)
int floor_powof2(int x) {
    int ans = 1;
    for (; x >= 2; x/=2)
        ans*=2;
    return ans;
}
int ceil_powof2(int x) {
    return floor_powof2(x*2-1);
}
```
## Primo  
```cpp  
isPrime
bool isPrime(ll n){
    if(n <= N) return P[n] == n;
    if(n%2 == 0) return false;
	int a[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

	ll d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
    	s++;
    	d >>= 1;
	}

	// It's guaranteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)
	for(int i = 0; i < 7; i++) {
   	 ll fp = fastPow(a[i], d, n);
    	bool comp = (fp != 1);
    	if(comp) for(int j = 0; j < s; j++) {
        	if (fp == n - 1) {
            	comp = false;
            	break;
        	}

        	fp = mulmod(fp,fp,n);
    	}
    	if(comp) return false;
	}
	return true;
}
```
## Factorizar numeros  
```cpp  
void factorize(ll n, map<ll,int> &M){
	if(n <= N){
    	while(n != 1){
        	++M[P[n]];
        	n /= P[n];
    	}
    	return;
	}

	if(isPrime(n)){
    	++M[n];
    	return;
	}

	ll d = brent(n);
	factorize(d,M); factorize(n/d,M);
}
```
