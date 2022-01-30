using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskSchedulingOrder {
 public:
  static vector<int> findOrder(int tasks, const vector<vector<int>>& prerequisites) {
    vector<int> sortedOrder;
    if (tasks <= 0) {
      return sortedOrder;
    }

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
      int front = sources.front();
      sources.pop();
      sortedOrder.push_back(front);
      vector<int> children = graph[front];
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    return sortedOrder.size() == tasks ? sortedOrder : vector<int>();
  }
};

int main(int argc, char* argv[]) {
  vector<int> result =
      TaskSchedulingOrder::findOrder(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
                             vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

