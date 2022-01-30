class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> results;
        if (num.size() == 0) return results;
        dfs(results, "", num, target, 0, 0, 0);
        return results;
    }

    // prev = tail, lo necesito para poder hacer la multiplicacion, ya que necesito mantener el orden de los factores
    void dfs(vector<string> &results, string path, string num, int target, int pos, long cur, long prev) {
        // base case
        if (pos == num.size()) {
            if (cur == target) {
                results.push_back(path);
            }
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            /*** corner-case-added-code ***/
            // sii empieza con 0, break
            if (num[pos] == '0' && i > pos) break;

            string str = num.substr(pos, i - pos + 1);
            // overflow
            long value = stol(str);
            // no puedo agregar operador al principio, entonces salteo
            if (pos == 0) {
                dfs(results, path + str, num, target, i + 1, value, value);
            }
            else {
            //  dfs(results, path            , num, target, pos  , cur        , prev);
                dfs(results, path + "+" + str, num, target, i + 1, cur + value, value);
                dfs(results, path + "-" + str, num, target, i + 1, cur - value, - value);
                dfs(results, path + "*" + str, num, target, i + 1, cur - prev + prev * value, prev * value);
            }
        }
    }
};
