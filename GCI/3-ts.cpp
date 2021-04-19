class TaskSchedulingOrder {
 public:
  static vector<int> findOrder(int tasks, const vector<vector<int>>& prerequisites) {
    vector<int> order;

    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> inDegree;
    for (int i = 0; i < tasks; i++) {
      inDegree[i] = 0;
      graph[i] = vector<int>();
    }

    for (int i = 0; i < prerequisites.size(); i++) {
      int parent = prerequisites[i][0];
      int child = prerequisites[i][1];
      graph[parent].push_back(child);
      inDegree[child]++;
    }

    queue<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    while (!sources.empty()) {
      int current = sources.front();
      sources.pop();
      order.push_back(current);
      vector<int> children = graph[current];
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    return order.size() == tasks ? order : vector<int>();
  }
};
