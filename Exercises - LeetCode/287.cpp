class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int previous = nums[0];
        for(int i=1; i<nums.size();i++){
            if(nums[i]==previous) return previous;
            else previous= nums[i];
        }
        return NULL;
    }
};
