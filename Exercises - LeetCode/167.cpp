class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int high = binarySearch(numbers, target);
        int low = 0;
        vector<int> result;
        while (low < high) {
            if(numbers[low] + numbers[high] == target) {
                result.push_back(low + 1);
                result.push_back(high + 1);
                return result;
            } else if (numbers[low] + numbers[high] > target) {
                high--;
            } else {
                low++;
            }
        }
        return result;
    }

    int binarySearch(vector<int> nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low < mid) {
            mid = low + ((high - low)/2);
            if (target <= nums[mid]) {
                if (target > nums[mid-1]) return mid;
                else high = mid-1;
            } else {
                low = mid;
            }
        }
        return low;
    }
};
