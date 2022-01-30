class Solution {
    
    // DP[i][j] = min(pivot + max(dp[start][pivot - 1], dp[pivot + 1][end]))
    
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 1));
        
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start <= n - len + 1; start++) {
                int end = start + len - 1;
                
                int currMin = INT_MAX;
                for (int pivot = start; pivot <= end; pivot++) {
                    currMin = min(currMin, pivot + max(dp[start][pivot - 1], dp[pivot + 1][end]));
                }
                dp[start][end] = currMin;
            }
        }
        
        return dp[1][n];
    }
};



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> sums;
        if (nums.size() < 3) return sums;
        unordered_map<string, int> ht;
        for (int i = 0; i < nums.size() -2; i++) {
            findTwo(nums, i+1, sums, ht, i);
        }
        return sums;
    }

    void findTwo(vector<int>& nums, int position, vector<vector<int>>& sums, unordered_map<string,int>& ht, int fixedPointer) {
        int leftPointer = position;
        int rightPointer = nums.size()-1;
        while (leftPointer < rightPointer) {
            int currentSum = nums[leftPointer] + nums[rightPointer];
            if (currentSum + nums[fixedPointer] == 0) {
                string str = "a"+to_string(nums[fixedPointer])+to_string(nums[leftPointer])+to_string(nums[rightPointer]);
                if (ht.find(str) != ht.end()) {
                    ht[str]++;
                    sums.push_back(vector<int>{nums[fixedPointer], nums[leftPointer], nums[rightPointer]});
                }
                return;
            } else {
                if (currentSum + nums[fixedPointer] > 0) rightPointer--;
                else leftPointer++;
            }
        }
    }
};
