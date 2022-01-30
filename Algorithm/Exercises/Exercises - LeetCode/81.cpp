class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {

            while (left < right && nums[left] == nums[left + 1]) left++; // skip duplicates from the left
            while (right > left && nums[right] == nums[right - 1]) right--; // skip duplicates from the right

            int middle = left + (right - left) / 2;
            if (nums[middle] == target) {
                return true;
            }
            // there exists rotation; the middle element is in the left part of the PIVOT
            if (nums[middle] > nums[right]) {
                 if (target < nums[middle] && target >= nums[left]) {
                     right = middle - 1;
                 } else {
                     left = middle + 1;
                 }
            }
            // there exists rotation; the middle element is in the right part of the PIVOT
            else if (nums[middle] < nums[left]) {
                if (target > nums[middle] && target <= nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
            // there is no rotation; just like normal binary search
            else {
                if (target < nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
        }
        return false;
    }
};
