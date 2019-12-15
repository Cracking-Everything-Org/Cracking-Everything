class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ht;
        vector<int> result;
        for(int i=0; i< nums.size(); i++){
            if(ht.find(target-nums[i]) != ht.end()){
                result.push_back(i);
                result.push_back(ht.find(target-nums[i])->second);
            }else ht[nums[i]]=i;
        }
        return result;
    }
};
