class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int totalWater = 0;

        vector<int> leftHeights(height.size());
        vector<int> rightHeights(height.size());

        leftHeights[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            leftHeights[i] = max(height[i], leftHeights[i-1]);
        }

        rightHeights[height.size()-1] = height[height.size()-1];
        for (int j = height.size() - 2 ; j >= 0; j--) {
            rightHeights[j] = max(height[j], rightHeights[j+1]);
        }

        for (int k = 0; k < height.size(); k++) {
            totalWater += min(leftHeights[k], rightHeights[k]) - height[k];
        }

        return totalWater;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        if (height.size() == 0) return result;
        vector<int> fromLeft(height.size(), 0);
        fromLeft[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            fromLeft[i] = max(fromLeft[i - 1], height[i]);
        }
        
        vector<int> fromRight(height.size(), 0);
        fromRight[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            fromRight[i] = max(fromRight[i + 1], height[i]);
        }
        
        for (int i = 0; i < height.size(); i++) {
            result += min(fromLeft[i], fromRight[i]) - height[i];
        }
        return result;
    }
};