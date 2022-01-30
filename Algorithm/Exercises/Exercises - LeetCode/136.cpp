class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            x1 = x1 ^ nums[i];
        }
        return x1;
    }
};
