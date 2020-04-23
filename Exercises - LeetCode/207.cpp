class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;
        unordered_map<int,vector<int>> adjacencyList;
        unordered_map<int,int> inDegree;
        int counter = 0;

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

        while (!sources.empty()) {
            int current = sources.front();
            sources.pop();
            counter++;
            for (int adjacent : adjacencyList[current]) {
                inDegree[adjacent]--;
                if (inDegree[adjacent] == 0) {
                    sources.push(adjacent);
                }
            }
        }

        return counter == numCourses;
    }
};
