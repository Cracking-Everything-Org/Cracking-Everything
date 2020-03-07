class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low<high){
            mid = low+(mid-low)/2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] > target){
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return nums[low] == target ? low : -1;
    }
};
