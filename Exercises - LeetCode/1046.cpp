class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        if (stones.size() == 0) return 0;
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if (first != second) pq.push(first - second);
        }
        if (pq.empty()) return 0;
        return pq.top();
    }
};
