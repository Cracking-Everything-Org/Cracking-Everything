class TopologicalSort {
 public:
  static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
    vector<int> result;

    // initialize
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> inDegree;
    for (int i = 0 ; i < vertices; i++) {
      inDegree[i] = 0;
      graph[i] = vector<int>();
    }

    // build
    for (int i = 0; i < edges.size(); i++) {
      int parent = edges[i][0];
      int child = edges[i][1];
      graph[parent].push_back(child);
      inDegree[child]++;
    }

    // find sources
    queue<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // process
    while (!sources.empty()) {
      int current = sources.front();
      sources.pop();
      result.push_back(current);
      vector<int> children = graph[current];
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    if (result.size() != vertices) return vector<int>();

    return result;
  }
};