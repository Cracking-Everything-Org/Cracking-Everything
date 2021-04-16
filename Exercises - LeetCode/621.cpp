class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int intervals = 0;
        unordered_map<char,int> ht;
        for (char t : tasks) {
            ht[t]++;
        }
        priority_queue<int> maxHeap;
        for (auto entry : ht) {
            maxHeap.push(entry.second);
        }

        while (!maxHeap.empty()) {
            vector<int> current;
            for (int i = 0; i <= n; i++) {
                if (!maxHeap.empty()) {
                    current.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }

            for (int j = 0; j < current.size(); j++) {
                if (current[j] > 1) {
                    maxHeap.push(current[j] - 1);
                }
            }

            intervals += maxHeap.empty() ? current.size() : n + 1;
        }

        return intervals;
    }
};