class Solution {
public:
    string alienOrder(vector<string>& words) {
        string topologicalOrder = "";
        
        unordered_map<char, int> inDegree;
        unordered_map<char, vector<char>> graph;
        
        for (int i = 0; i < words.size() - 1; i++) {
            string first = words[i];
            string second = words[i + 1];
            
            int minLength = min(first.length(), second.length());
            for (int j = 0; j < minLength; j++) {
                if (first[j] != second[j]) {
                    char parent = min(first[j], second[j]);
                    char child = max(first[j], second[j]);
                    
                    if (inDegree.find(child) == inDegree.end()) inDegree[child] = 0;
                    if (inDegree.find(parent) == inDegree.end()) inDegree[parent] = 0;
                    if (graph.find(parent) == graph.end()) graph[parent] = vector<char>();
                    
                    inDegree[child]++;
                    graph[parent].push_back(child);
                }
            }
        }
            
        queue<char> sources;
        for (auto entry : inDegree) {
            if (entry.second == 0) {
                sources.push(entry.first);
            }
        }
        
        while (!sources.empty()) {
            char current = sources.front();
            sources.pop();
            topologicalOrder += current;
            vector<char> children = graph[current];
            for (auto child : children) {
                inDegree[child]--;
                if (inDegree[child] == 0) {
                    sources.push(child);
                }
            }
        }
        
        return topologicalOrder;
    }
};