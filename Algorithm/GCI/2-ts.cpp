class TaskScheduling {
 public:
  static bool isSchedulingPossible(int tasks, const vector<vector<int>>& prerequisites) {
    vector<int> topologicalSort;

    // initialize
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> inDegree;
    for (int i = 0; i < tasks; i++) {
      graph[i] = vector<int>();
      inDegree[i] = 0;
    }

    // build
    for (int i = 0; i < prerequisites.size(); i++) {
      int parent = prerequisites[i][0];
      int child = prerequisites[i][1];
      inDegree[child]++;
      graph[parent].push_back(child);
    }

    // sources
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
      topologicalSort.push_back(current);
      vector<int> children = graph[current];
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    return topologicalSort.size() == tasks;
  }
};