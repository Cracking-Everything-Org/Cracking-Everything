class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int triplets = 0;
        int size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            triplets += twoSumSmaller(nums, i + 1, target - nums[i]);
        }
        return triplets;
    }

    int twoSumSmaller(vector<int>& nums, int left, int target) {
        int sum = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                sum += right - left;
                left++;
            } else {
                right--;
            }
        }
        return sum;
    }
};
