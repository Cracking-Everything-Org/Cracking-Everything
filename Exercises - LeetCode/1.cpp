class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ht;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (ht.find(target - nums[i]) != ht.end()) {
                result.push_back(i);
                result.push_back(ht.find(target - nums[i])->second);
            } else ht[nums[i]] = i;
        }
        return result;
    }
};

//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> two = findTwo(nums, target);
        vector<int> ans(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == two[0] || nums[i] == two[1]) {
                if (ans[0] == -1) ans[0] = i;
                else ans[1] = i;
            }
        }
        return ans;
    }

    vector<int> findTwo(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;
        while (leftPointer < rightPointer) {
            int sum = nums[leftPointer] + nums[rightPointer];
            if (sum == target) {
                return {nums[leftPointer], nums[rightPointer]};
            }
            if (target > sum) {
                leftPointer++;
            }
            if (target < sum){
                rightPointer--;
            }
        }
        return vector<int>{-1, -1};
    }
};
