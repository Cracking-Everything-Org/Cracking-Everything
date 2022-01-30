class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int start = 0;
        int end = 0;
        int totalCost = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        while (start < s.length()) {
            while (s[start] == s[end]) {
                end++;
            }
            if (end - start > 0) {
                for (int i = start; i < end; i++) {
                    minHeap.push(cost[i]);
                }
                for (int j = 1; j < end - start; j++) {
                    totalCost += minHeap.top();
                    minHeap.pop();
                }
                while (!minHeap.empty()) {
                    minHeap.pop();
                }
            }
            start = end;
        }
        return totalCost;
    }
};
