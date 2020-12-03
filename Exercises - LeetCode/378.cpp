class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;

        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                maxHeap.push(matrix[row][col]);
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
        }

        return maxHeap.top();
    }
};