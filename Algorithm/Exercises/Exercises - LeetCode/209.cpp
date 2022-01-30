class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minimumLen = INT_MAX;
        int currentSum = 0;

        int startPointer = 0;

        for (int endPointer = 0; endPointer < nums.size(); endPointer++) {
            currentSum += nums[endPointer];

            while (currentSum >= s) {
                minimumLen = min(minimumLen, endPointer - startPointer + 1);
                currentSum -= nums[startPointer];
                startPointer++;
            }
        }
        return minimumLen == INT_MAX ? 0 : minimumLen;
    }
};
