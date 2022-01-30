class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // binary search, lo corro dos veces, uno para cada extremo
        vector<int> ans(2);
        ans[0] = findStartingIndex(nums, target);
        ans[1] = findEndingIndex(nums,target);
        return ans;
    }

    int findStartingIndex(vector<int> nums, int target) {
        int index = -1;
        int left = 0;
        int right = nums.size()-1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
            if (nums[middle] == target) {
                index = middle;
            }
        }
        return index;
    }

    int findEndingIndex(vector<int> nums, int target) {
        int index = -1;
        int left = 0;
        int right = nums.size()-1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] <= target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
            if (nums[middle] == target) {
                index = middle;
            }
        }
        return index;
    }

};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        result[0] = search(nums, target, false);
        if (result[0] != -1) {
            result[1] = search(nums, target, true);
        }
        return result;
    }
    
    int search(vector<int>& nums, int target, bool findMaxIndex) {
        int targetIndex = -1;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                targetIndex = mid;
                if (findMaxIndex) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return targetIndex;
    }
};
