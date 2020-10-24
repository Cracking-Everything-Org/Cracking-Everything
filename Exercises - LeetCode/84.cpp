class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> stk;
        int i = 0;
        int n = heights.size();
        int top;
        int currentArea = 0;
        while (i < n) {
            if (stk.empty() || heights[i] > heights[stk.top()]) {
                stk.push(i++);
            } else {
                top = stk.top();
                stk.pop();
                currentArea = heights[top] * (stk.empty() ? i : i - stk.top() - 1);
                maxArea = currentArea > maxArea ? currentArea : maxArea;
            }
        }

        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            currentArea = heights[top] * (stk.empty() ? i : i - stk.top() - 1);
            maxArea = currentArea > maxArea ? currentArea : maxArea;
        }

        return maxArea;
    }
};
