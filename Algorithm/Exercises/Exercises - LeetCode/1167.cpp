class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int result = 0;
        priority_queue<int, vector<int>, compare> minHeap;
        for (int i = 0; i < sticks.size(); i++) {
            minHeap.push(sticks[i]);
        }

        while (minHeap.size() > 1) {
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            int connected = first + second;
            result += connected;
            minHeap.push(connected);
        }
        return result;
    }

    struct compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
};
