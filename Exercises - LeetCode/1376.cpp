class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> manages;
        for (int i = 0; i < n; i++) {
            if (manages.find(manager[i]) == manages.end()) {
                manages[manager[i]] = vector<int>();
            }
            manages[manager[i]].push_back(i);
        }
        int maxTime = INT_MIN;
        queue<pair<int, int>> q;
        q.push(make_pair(-1,0));
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            maxTime = max(maxTime, current.second);
            if (manages.find(current.first) != manages.end()) {
                for (auto employee : manages[current.first]) {
                    q.push(make_pair(employee, current.second + informTime[employee]));
                }
            }
        }
        return maxTime;
    }
};
