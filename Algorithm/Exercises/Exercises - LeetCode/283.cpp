class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a = 0;
        int z = 0;
        while (a < nums.size() && z < nums.size()) {
            if (a >= z) {
                swap(nums[a], nums[z]);
                a++;
            } else a++;
            while (z < nums.size() && nums[z] != 0) z++;
            while (a < nums.size() && nums[a] == 0) a++;
        }
    }
};
