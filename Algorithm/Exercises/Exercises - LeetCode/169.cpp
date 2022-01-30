class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ht;
        for(int i=0; i<nums.size(); i++){
            if(ht.find(nums[i]) != ht.end()){
                ht.insert({nums[i], 1});
            }else {
                ht.insert({nums[i], nums[i]++});
            }
        }
        for (auto it : ht) {
            if (it.second > (nums.size() / 2)) {
                return it.first;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //no me acuerdo de bit manipulation XD
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
