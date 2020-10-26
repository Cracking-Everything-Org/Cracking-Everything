class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &n : hand)
            pq.push(n);
        while (pq.size()) {
            int n = pq.top();
            vector<int> temp;
            for (int i = n; i < n + W; i++) {
                if (pq.top() == i)
                    pq.pop();
                else
                    return false;
                // handle duplicates
                 while (pq.size() and pq.top() == i) {
                    pq.pop();
                    temp.push_back(i);
                }
            }
            // insert duplicates back
            for (auto &t : temp)
                pq.push(t);
        }
        return true;
    }
};
