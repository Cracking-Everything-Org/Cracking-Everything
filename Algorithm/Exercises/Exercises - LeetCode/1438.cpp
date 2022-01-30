class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // SLIDING WINDOW + DEQUE speed: O(n) , space: O(n)

        int longestSize = 0;
        deque<int> minQueue;
        deque<int> maxQueue;
        int endWindow = 0;
        int startWindow = 0;

        while (endWindow < nums.size()) {

            int endElement = nums[endWindow];

            while (!minQueue.empty() && nums[minQueue.back()] >= endElement) minQueue.pop_back();
            minQueue.push_back(endWindow);

            while (!maxQueue.empty() && nums[maxQueue.back()] <= endElement) maxQueue.pop_back();
            maxQueue.push_back(endWindow);

            if (nums[maxQueue.front()] - nums[minQueue.front()] > limit) {
                startWindow++;
                if (startWindow > minQueue.front()) minQueue.pop_front();
                if (startWindow > maxQueue.front()) maxQueue.pop_front();
            } else {
                longestSize = max(longestSize, endWindow - startWindow + 1);
                endWindow++;
            }
        }
        return longestSize;
    }
};
