class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0;
        int seenTwice = 0;
        for (int i = 0; i < nums.size(); i++) {
            seenOnce = ~seenTwice & (seenOnce ^ nums[i]);
            seenTwice = ~seenOnce & (seenTwice ^ nums[i]);
        }
        return seenOnce;
    }
};
