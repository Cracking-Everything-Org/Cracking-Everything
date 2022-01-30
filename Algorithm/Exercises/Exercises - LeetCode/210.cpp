class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adjacencyList;
        unordered_map<int,int> inDegree;

        for (int i = 0; i < numCourses; i++) {
            inDegree[i] = 0;
            adjacencyList[i] = vector<int>();
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            adjacencyList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        queue<int> sources;
        for (auto entry : inDegree) {
            if (entry.second == 0) {
                sources.push(entry.first);
            }
        }

        vector<int> order;
        while (!sources.empty()) {
            int current = sources.front();
            sources.pop();
            order.push_back(current);
            for (auto adjacent : adjacencyList[current]) {
                inDegree[adjacent]--;
                if (inDegree[adjacent] == 0) {
                    sources.push(adjacent);
                }
            }
        }

        return order.size() == numCourses ? order : vector<int>();
    }
};
