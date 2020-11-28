class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        for (int i=0; i<n; i++) {
            color[i] =-1;
        }

        for (int start=0; start<n; ++start) {
            if (color[start] == -1) {
                stack<int> stk;
                stk.push(start);
                color[start] = 0;

                while (!stk.empty()) {
                    int node = stk.top();
                    stk.pop();
                    for (int nei: graph[node]) {
                        if (color[nei] == -1) {
                            stk.push(nei);
                            color[nei] = color[node]^1;
                        } else {
                            if (color[nei] == color[node]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
