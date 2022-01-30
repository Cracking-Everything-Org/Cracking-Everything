#include <algorithm>
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        int len = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(m.count(sum - k)) len = max(len, i - m[sum - k]);
            if(!m.count(sum)) m[sum] = i;
        }
        return len == INT_MIN ? 0: len;
    }
};
