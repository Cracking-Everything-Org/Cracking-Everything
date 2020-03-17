class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int firstPointer = 0;
        for (int secondPointer = firstPointer+1; secondPointer < nums.size(); secondPointer++) {
            if (nums[secondPointer] != nums[firstPointer]) {
                swap(nums[secondPointer], nums[firstPointer + 1]);
                firstPointer++;
            }
        }
        return firstPointer + 1;
    }
};
