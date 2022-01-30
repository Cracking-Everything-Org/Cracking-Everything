class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answers;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(i, nums, answers);
            }
        }
        
        return answers;
    }
    
    void twoSum(int current, vector<int>& nums, vector<vector<int>>& answers) {
        int left = current + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right] + nums[current];
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--; 
            } else {
                answers.push_back({ nums[current], nums[left++], nums[right--] });
                while (left < right && nums[left] == nums[left - 1])
                    left++;            
            }
        }
    }
};