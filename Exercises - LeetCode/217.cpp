class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> frequency;
        for (auto num : nums) {
            if (frequency.find(num) != frequency.end()) return true;
            frequency.insert(num);
        }
        return false;
    }
};