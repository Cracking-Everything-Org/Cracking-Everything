class Solution {
public:
    int numSimilarGroups(vector<string>& A) {

        // DIVIDE AND CONQUER
        // armo un grafo y realizo un dfs para saber la cantidad

        unordered_map<string, unordered_set<string>> graph;
        buildGraph(graph, A);

        int count = 0;
        unordered_set<string> visited;
        for (auto entry : graph) {
            if (visited.find(entry.first) != visited.end()) continue;
            dfs(visited, entry.first, graph);
            count++;
        }
        return count;
    }

    void buildGraph(unordered_map<string, unordered_set<string>>& graph  ,vector<string>& A) {
        for (string s : A) {
            graph[s] = unordered_set<string>();
        }

        for (int i = 0; i < A.size() - 1; i++) {
            for (int j = i + 1; j  < A.size(); j++) {
                if (isSimilar(A[i], A[j])) {
                    graph[A[i]].insert(A[j]);
                    graph[A[j]].insert(A[i]);
                }
            }
        }
    }

    bool isSimilar(string A, string B) {
        int len = A.length();
        int diff = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] != B[i]) {
                diff++;
                if (diff > 2) {
                    return false;
                }
            }
        }
        return true;
    }

    void dfs(unordered_set<string>& visited, string current, unordered_map<string, unordered_set<string>>& graph) {
        visited.insert(current);
        if (graph[current].size() == 0) return;
        for (string next : graph[current]){
            if (visited.find(next) != visited.end()) continue;
            dfs(visited, next, graph);
        }
    }
};
