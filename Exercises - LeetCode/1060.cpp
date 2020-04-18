class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        // encontrar cantidad de perdidos entre index y primero
        // nums[i] - nums[0] - i

        int left = 0;
        int right = nums.size() - 1; // hay un bug, debe ser int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (missingBetween(mid, nums) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left - 1] + k - missingBetween(left - 1, nums);
    }

    int missingBetween(int index, vector<int> nums) {
        return nums[index] - nums[0] - index;
    }
};
