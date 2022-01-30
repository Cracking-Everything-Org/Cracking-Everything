class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (!nums.size()) return INT_MIN;
        sort(nums.begin(), nums.end());
        int closestSum = INT_MAX;
        int size = nums.size();
        for (int i = 0; i < size && closestSum != 0; i++) {
            // Lo mas clean sería definir la funcion Two sum afuera
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[right] + nums[left];
                if (abs(target - sum) < abs(closestSum)) {
                    closestSum = target - sum;
                }
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return target - closestSum;
    }
};
