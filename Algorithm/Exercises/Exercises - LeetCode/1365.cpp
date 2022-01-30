class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        vector<int> indices(nums.size(), -1);
        
        if (!nums.size()) return sorted;
        sort(sorted.begin(), sorted.end());
        
        for (int i = 0; i < nums.size(); i++) {
            indices[i] = binarySearch(nums[i], sorted);
        }
        
        return indices;
    }
    
    int binarySearch(int target, vector<int> list) {
        int left = 0;
        int right = list.size() - 1;
        
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (list[middle] < target) {
                left = middle + 1;
            } else if (list[middle] > target) {
                right = middle - 1;
            } else {
                while (middle > 0 && list[middle] == target && list[middle] == list[middle - 1]) {
                    middle--;
                }
                return middle;
            }
        }
        
        return -1;
    }
};