class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // paso todo a un set para tener orden constante
        unordered_set<string> deads(deadends.begin(), deadends.end());
        if (deads.count("0000")) {
            return -1;
        }
        if (target == "0000") {
            return 0;
        }
        set<string> visited;
        queue<string> toProcess;
        toProcess.push("0000");
        for (int distance = 1; !toProcess.empty(); distance++) {
            for (int n = toProcess.size(); n > 0; n--) {
                string current = toProcess.front();
                toProcess.pop();
                for (int i = 0; i < 4; i++) {
                    for (int dif = 1; dif <= 9; dif += 8) {
                        string newRotation = current;
                        newRotation[i] = (newRotation[i] - '0' + dif) % 10 + '0';
                        if (newRotation == target) {
                            return distance;
                        }
                        if (!deads.count(newRotation) && !visited.count(newRotation)) {
                            toProcess.push(newRotation);
                        }
                        visited.insert(newRotation);
                    }
                }
            }
        }
        return -1;
    }
};
