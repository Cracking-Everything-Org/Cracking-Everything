class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool permutationDone = false;
        for (int i=nums.size()-1; i > 0 && !permutationDone ; i--) {
            if (nums[i] > nums[i-1]) {
                swap(nums[i-1], nums[nums.size()-1]); // CASE: [1,3,2] = [2,1,3]
                sort(nums.begin() + i, nums.end());
                reverse(nums.begin() + i, nums.end());
                permutationDone = true;
            }
        }
        if (!permutationDone) {
            reverse(nums.begin(), nums.end());
        }
    }
};
