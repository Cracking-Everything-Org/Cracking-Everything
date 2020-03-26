class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0;
        int right = nums.size()-1;
        if (nums[right] > nums[0]) return nums[0];

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > nums[middle + 1]) {
                return nums[middle + 1];
            }
            if (nums[middle - 1] > nums[middle]) {
                return nums[middle];
            }
            if (nums[middle] > nums[0]) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return -1;
    }
};
