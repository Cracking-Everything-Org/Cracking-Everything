class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topologicalOrder;
        
        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> graph;
        
        for (int i = 0; i < numCourses; i++) {
            graph[i] = vector<int>();
            inDegree[i] = 0;
        }
        
        for (vector<int> prerequisite : prerequisites) {
            int parent = prerequisite[0];
            int child = prerequisite[1];
            graph[parent].push_back(child);
            inDegree[child]++;
        }
        
        queue<int> sources;
        for (auto entry : inDegree) {
            if (entry.second == 0) {
                sources.push(entry.first);
            }
        }
        
        while(!sources.empty()) {
            int current = sources.front();
            sources.pop();
            topologicalOrder.push_back(current);
            vector<int> children = graph[current];
            for (auto child : children) {
                inDegree[child]--;
                if (inDegree[child] == 0) {
                    sources.push(child);
                }
            }
        }
        
        return topologicalOrder.size() == numCourses;
    }
};