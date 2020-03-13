class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());

        answer[0] = 1;
        for (int i=1; i<nums.size(); i++) {
            answer[i] = nums[i-1] * answer[i-1];
        }

        int R = 1;
        for (int j=nums.size()-1; j>=0; j--) {
            answer[j] = answer[j] * R;
            R*= nums[j];
        }
        return answer;
    }
};
