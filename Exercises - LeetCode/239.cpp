class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> maxList;

        int startPointer = 0;
        int currentMax = INT_MIN;
        for (int endPointer = 0; endPointer < nums.size(); endPointer++) {

            if (endPointer - startPointer + 1 == k) {
                for (int i=0; i<k ; i++) {
                    currentMax = max(currentMax, nums[startPointer + i]);
                }
                maxList.push_back(currentMax);
                currentMax = INT_MIN;
                startPointer ++;
            }
        }

        return maxList;
    }
};
