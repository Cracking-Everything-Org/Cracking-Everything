class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> bob;
        unordered_map<int,int> alice;
        int count = 0;

        vector<int> bobReach(n + 1, 0);
        vector<int> aliceReach(n + 1, 0);

        for (auto edge : edges) {
            if (edge[0] == 3) {
                if (bob.find(edge[2]) != bob.end()) {
                    count++;
                } else {
                    bob[edge[2]] = edge[1];
                }

                if (alice.find(edge[2]) != alice.end()) {
                    count++;
                } else {
                    alice[edge[2]] = edge[1];
                }
            } else if (edge[0] == 2) {
                if (bob.find(edge[2]) != bob.end()) {
                    count++;
                } else {
                    bob[edge[2]] = edge[1];
                }
            } else {
                if (alice.find(edge[2]) != alice.end()) {
                    count++;
                } else {
                    alice[edge[2]] = edge[1];
                }
            }
        }

        for (auto entry : bob) {
            bobReach[entry.first]++;
            bobReach[entry.second]++;
        }

        for (int i = 0; i < bobReach.size(); i++) {
            if (bobReach[i] > 1) {
                count -= bobReach[i] - 1;
            }
        }

        for (auto entry : alice) {
            aliceReach[entry.first]++;
            aliceReach[entry.second]++;
        }

        for (int i = 0; i < aliceReach.size(); i++) {
            if (aliceReach[i] > 1) {
                count -= aliceReach[i] - 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!bobReach[i] || !aliceReach[i]) {
                return -1;
            }
        }

        return count;
    }
};
