class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
      /*
        DFS, para cada nodo
      */
      int diameter = 0; //global maximum

      // necesito saber cuales ya visité
      vector<bool> visited(edges.size() + 1);
      vector<vector<int>> neighbors(edges.size() + 1);
      for (auto& e : edges) {
        // agrego hacia ambos lados porque es no dirigido
        neighbors[e[0]].push_back(e[1]);
        neighbors[e[1]].push_back(e[0]);
      }
        //Empieza en 0, Each node has labels in the set {0, 1, ..., edges.length}
      return dfs(neighbors, visited, 0, diameter);
    }

    int dfs(vector<vector<int>>& neighbors, vector<bool>& visited, int currentNode, int& diameter) {
      visited[currentNode] = true;
      int max_depth = 0; // current depth
      for (auto neighbor : neighbors[currentNode]) {
        if (!visited[neighbor]) {
          int depth = dfs(neighbors, visited, neighbor, diameter);
            // actualizo global
          diameter = max(diameter, depth + max_depth);
            // actualizo current
          max_depth = max(depth, max_depth);
        }
      }
        // si recorri todo, retorno el diametro, de lo contrario retorno el depth + 1 para resultado local
      return currentNode == 0 ? diameter : max_depth + 1;
    }

};
