class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // genero las combinaciones, uso dfs
        // p = target / min(candidates[i])
        // n = size of candidates
        // C(n,r) = (n+r-1)! / (n-1)r!   es la formula de combinaciones
        // time = O(C(n,1)+ C(n,2)+...+C(n,p))
        // space = O (path + recursion stack) = O(p)
        vector<vector<int>> res;
        vector<int> path;
        // ordeno para no continuar generando una vez que me pase del target
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, res, path);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int currentIndex, vector<vector<int>>& res, vector<int> path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = currentIndex; i < candidates.size(); i++) {
            // caso en el que me pasé
            if (candidates[i] > target) {
                return;
            }

            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, res, path);
            // lo quito del path
            path.pop_back();
        }
    }
};
