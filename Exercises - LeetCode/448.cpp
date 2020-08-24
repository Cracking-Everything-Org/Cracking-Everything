class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> disappeared;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }


        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                disappeared.push_back(i + 1);
            }
        }
        return disappeared;
    }
};
