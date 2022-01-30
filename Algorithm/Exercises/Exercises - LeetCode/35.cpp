class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid = 0;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            mid = low + ((high - low) / 2);
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
