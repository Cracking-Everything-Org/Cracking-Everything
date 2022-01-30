class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto num : nums) {
            minHeap.push(num);
        }
        while (!minHeap.empty()) {
            int current = minHeap.top();
            vector<int> duplicates;
            for (int i = current; i < current + k; i++) {
                if (minHeap.top() == i) {
                    minHeap.pop();
                } else {
                    return false;
                }
                while (!minHeap.empty() && minHeap.top() == i) {
                    minHeap.pop();
                    duplicates.push_back(i);
                }
            }
            for (int i = 0; i < duplicates.size(); i++) {
                minHeap.push(duplicates[i]);
            }
        }
        return true;
    }
};
