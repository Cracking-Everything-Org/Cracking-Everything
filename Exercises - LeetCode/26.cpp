class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int startPointer = 0;
        int checkPointer = 0;
        while (checkPointer < nums.size()) {
            nums[startPointer] = nums[checkPointer];
            while (checkPointer < nums.size() && nums[startPointer] == nums[checkPointer]) {
                checkPointer++;
            }
            startPointer++;
        }
        return startPointer;
    }
};
