class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int components = 0;
        
        vector<vector<int>> adjacencyList(n);
        
        for (auto edge : edges) {
            int parent = edge[0];
            int child = edge[1];
            adjacencyList[parent].push_back(child);
            adjacencyList[child].push_back(parent);
        }
        
        unordered_set<int> seen;
        
        for (int current = 0; current < adjacencyList.size(); current++) {
            vector<int> children = adjacencyList[current];
            
            if (seen.find(current) == seen.end()) {
                components++;
                seen.insert(current);
            }
                
            for (auto child : children) {
                dfs(child, seen, adjacencyList);
            }
        }
        
        return components;
    }
    
    void dfs(int current, unordered_set<int>& seen, vector<vector<int>>& adjacencyList) {
        vector<int> children = adjacencyList[current];
        if (seen.find(current) == seen.end()) {
            seen.insert(current);
            for (auto child : children) {
                dfs(child, seen, adjacencyList);
            }
        }
    }
};