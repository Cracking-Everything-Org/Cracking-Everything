class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nextNotInPlace = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[nextNotInPlace] == 0) nextNotInPlace++;
            else if (nums[i] == 0) {
                swap(nums[i], nums[nextNotInPlace]);
                nextNotInPlace++;
            }
        }
        for (int i = nextNotInPlace; i < nums.size() && nextNotInPlace < nums.size(); i++){
            if (nums[nextNotInPlace] == 1) nextNotInPlace++;
            else if (nums[i] == 1) {
                swap(nums[i], nums[nextNotInPlace]);
                nextNotInPlace++;
            }
        }
    }
};
