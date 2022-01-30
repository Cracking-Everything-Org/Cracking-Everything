class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        if (total % 2 != 0) return false;

        int target = total / 2;

        unordered_map<int, bool> memo;
        return canPart(memo, nums, nums.size() - 1, target);
    }

    bool canPart(unordered_map<int, bool>& memo, vector<int>& nums, int index, int subSetSum) {
        if (subSetSum == 0) {
            return true;
        }
        if (subSetSum < 0 || index == 0) {
            return false;
        }

        if (memo.find(subSetSum) != memo.end()) {
            return memo[subSetSum];
        }

        bool including = false;
        if (subSetSum - nums[index] >= 0) {
            including = canPart(memo, nums, index - 1, subSetSum - nums[index]);
        }
        bool excluding = canPart(memo, nums, index - 1, subSetSum);
        memo[subSetSum] = including || excluding;
        return including || excluding;
    }

};
