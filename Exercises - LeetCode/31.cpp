class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) { // me muevo mientras el izquierdo sea menor
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) { // me muevo mientras el End sea menor que el que encontré antes
                j--;
            }
            swap(nums[i], nums[j]); // swapeo
        }
        reverse(nums.begin() + i + 1, nums.end()); // invierto lo que esta entre
    }
};