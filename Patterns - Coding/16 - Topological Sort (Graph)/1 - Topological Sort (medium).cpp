Topological Sort of a directed graph (a graph with unidirectional edges) is a linear ordering of its vertices such that for every directed edge (U, V) from vertex U to vertex V, U comes before V in the ordering.

Given a directed graph, find the topological ordering of its vertices.

Example 1:

Input: Vertices=4, Edges=[3, 2], [3, 0], [2, 0], [2, 1]
Output: Following are the two valid topological sorts for the given graph:
1) 3, 2, 0, 1
2) 3, 2, 1, 0
    3
    2
    0
    1
Example 2:

Input: Vertices=5, Edges=[4, 2], [4, 3], [2, 0], [2, 1], [3, 1]
Output: Following are all valid topological sorts for the given graph:
1) 4, 2, 3, 0, 1
2) 4, 3, 2, 0, 1
3) 4, 3, 2, 1, 0
4) 4, 2, 3, 1, 0
5) 4, 2, 0, 3, 1
    4
    2
    3
    0
    1
Example 3:

Input: Vertices=7, Edges=[6, 4], [6, 2], [5, 3], [5, 4], [3, 0], [3, 1], [3, 2], [4, 1]
Output: Following are all valid topological sorts for the given graph:
1) 5, 6, 3, 4, 0, 1, 2
2) 6, 5, 3, 4, 0, 1, 2
3) 5, 6, 4, 3, 0, 2, 1
4) 6, 5, 4, 3, 0, 1, 2
5) 5, 6, 3, 4, 0, 2, 1
6) 5, 6, 3, 4, 1, 2, 0

There are other valid topological ordering of the graph too.

vector<int> sort(int vertices, const vector<vector<int>>& edges) {
  vector<int> sortedOrder;
  if(vertices <= 0) return sortedOrder;

  // initialization
  unordered_map<int, vector<int>> adjacencyList;
  unordered_map<int, int> inDegree;
  for(int i=0; i < vertices; i++) {
    adjacencyList[i] = vector<int>();
    inDegree[i] = 0;
  }

  // build
  for(int i=0; i < edges.size(); i++) {
    int parent = edges[i][0];
    int child = edges[i][1];
    adjacencyList[parent].push_back(child);
    inDegree[child]++;
  }

  // find sources
  queue<int> sources;
  for(auto entry : inDegree){
    if(entry.second == 0){
      sources.push(entry.first);
    }
  }

  // sort
  while(!sources.empty()){
    int vertex = sources.front();
    sources.pop();
    sortedOrder.push_back(vertex);
    vector<int> children = adjacencyList[vertex];
    for(auto child : children){
      inDegree[child] --;
      if(inDegree[child] == 0){
        sources.push(child);
      }
    }
  }

  if(sortedOrder.size() != vertices){
    return vector<int>();
  }

  return sortedOrder;
}

Time Complexity #
In step ‘d’, each vertex will become a source only once and each edge will be accessed and removed once. Therefore, the time complexity of the above algorithm will be O(V+E), where ‘V’ is the total number of vertices and ‘E’ is the total number of edges in the graph.

Space Complexity #
The space complexity will be O(V+E), since we are storing all of the edges for each vertex in an adjacency list.
