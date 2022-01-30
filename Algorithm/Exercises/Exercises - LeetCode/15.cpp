#pragma GCC optimise ("Ofast")
static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int n = nums.size();
        if(n == 0) return output;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(i > 0 and nums[i-1] == nums[i]) continue;
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else{
                    output.push_back({nums[i], nums[left++], nums[right--]});
                    while(left < right and nums[left] == nums[left-1]) left++;
                    while(left < right and nums[right] == nums[right+1]) right--;
                }
            }
        }
        return output;
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
