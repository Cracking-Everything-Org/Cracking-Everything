class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> views;
        int size = heights.size();
        vector<int> rightView(size, 0);
        rightView[size - 1] = heights[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            rightView[i] = max(rightView[i + 1], heights[i]);
        }
        for (int i = 0; i < size - 1; i++) {
            if (rightView[i] != rightView[i + 1] && heights[i] == rightView[i]) {
                views.push_back(i);
            }
        }
        if (rightView[size - 1] != 0) views.push_back(size - 1);
        return views;
    }
};