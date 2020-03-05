There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite tasks which need to be completed before it can be scheduled. Given the number of tasks and a list of prerequisite pairs, write a method to find the ordering of tasks we should pick to finish all tasks.

Example 1:

Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
Output: [0, 1, 2]
Explanation: To execute task '1', task '0' needs to finish first. Similarly, task '1' needs to finish
before '2' can be scheduled. A possible scheduling of tasks is: [0, 1, 2]
Example 2:

Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
Output: []
Explanation: The tasks have cyclic dependency, therefore they cannot be scheduled.
Example 3:

Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
Output: [0 1 4 3 2 5]
Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5]

vector<int> findOrder(int tasks, const vector<vector<int>>& prerequisites) {
  vector<int> sortedOrder;
  if (tasks <= 0) {
    return sortedOrder;
  }
  // TODO: Write your code here
  unordered_map<int, vector<int>> adjacencyList;
  unordered_map<int, int> inDegree;
  for(int i=0; i<tasks; i++){
    adjacencyList[i] = vector<int>();
    inDegree[i] = 0;
  }

  for (int i = 0; i < prerequisites.size(); i++) {
    int parent = prerequisites[i][0];
    int child = prerequisites[i][1];
    adjacencyList[parent].push_back(child);
    inDegree[child]++;
  }

  queue<int> sources;
  for (auto entry : inDegree){
    if(entry.second == 0){
      sources.push(entry.first);
    }
  }


  while(!sources.empty()){
    int vertex = sources.front();
    sources.pop();
    sortedOrder.push_back(vertex);
    vector<int> children = adjacencyList[vertex];
    for (auto child : children) {
      inDegree[child]--;
      if(inDegree[child] == 0){
        sources.push(child);
      }
    }
  }

  return sortedOrder;
}

Time complexity #
In step ‘d’, each task can become a source only once and each edge (prerequisite) will be accessed and removed once. Therefore, the time complexity of the above algorithm will be O(V+E), where ‘V’ is the total number of tasks and ‘E’ is the total number of prerequisites.

Space complexity #
The space complexity will be O(V+E), since we are storing all of the prerequisites for each task in an adjacency list.
