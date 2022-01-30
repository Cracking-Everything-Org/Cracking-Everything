class Solution {
public:
     bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return 0;
        vector<vector<int>> adjacencyList(n);
         
        for (auto& v : edges) {
            adjacencyList[v[0]].push_back(v[1]);
            adjacencyList[v[1]].push_back(v[0]);
        }
         
        vector<bool> seen(n);
        if (dfs(-1, 0, seen, adjacencyList)) {
            return false;
        }
         
        return accumulate(seen.begin(),seen.end(),0) == n;
    }
    
    bool dfs(int from, int to, vector<bool>& seen, vector<vector<int>>& adjacencyList) {
        if (seen[to]) return true;
        seen[to] = 1;
        for (int child : adjacencyList[to]) {
            if (child != from && dfs(to, child, seen, adjacencyList)) {
                return true;
            }
        }
        
        return false;
    }
};