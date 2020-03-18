class Solution {
public:

    // existen ciclos, por lo que se puede resolver de forma greedy usando simple backtracking e ir guardando los aeropuertos

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string, vector<string>> adjacencyList;
        unordered_map<string, int> inDegree;

        for (auto ticket : tickets) {
            inDegree[ticket[1]]++;
            if (adjacencyList.find(ticket[0]) != adjacencyList.end()) {
                adjacencyList[ticket[0]].push_back(ticket[1]);
            } else {
                adjacencyList[ticket[0]] = vector<string>{ticket[1]};
            }
        }

        queue<string> q;
        for (auto entry : inDegree) {
            if (entry.second == 0) {
                q.push(entry.first);
            }
        }

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            ans.push_back(current);
            int size = adjacencyList[current].size();
            string minDegree;
            for (int i = 0; i < size; i++) {
                minDegree = adjacencyList[current[i]] < adjacencyList[minDegree] ? current[i] : minDegree;
            }
            if (minDegree.size() > 0) {
                q.push(minDegree);
                for (auto str : current) {
                    if (*str == minDegree) {
                        adjacencyList[current].erase(i);
                    }
                }
            }
        }

        return ans;
    }
};
