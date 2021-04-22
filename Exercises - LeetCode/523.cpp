class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int pre = 0;
        unordered_set<int> hs;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (hs.count(mod)) {
                return true;
            }
            hs.insert(pre);
            pre = mod;
        }
        return false;
    }
};