class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ways = 0;
        for (int i = 0; i < nums.size(); i++) {
            int endWindow = i;
            long long current = 1;
            while (endWindow < nums.size()) {
                current *= nums[endWindow];
                //cout << "before 0 current " << i << ": " << current << endl;
                if (current == 0) break;
                //cout << "after 0 current: " << i << ": "  << current << endl;
                if (current > LLONG_MAX) {
                    return endWindow - i + 1;
                }
                if (current > 0) {
                    ways = ways >= endWindow - i + 1 ? ways : endWindow - i + 1;
                    //cout << "current > 0 ?: " << endWindow - i + 1 << endl;
                }
                endWindow++;
            }
            //cout << "ways de " << i << ": " << ways << endl;
        }
        return ways;
    }
};
