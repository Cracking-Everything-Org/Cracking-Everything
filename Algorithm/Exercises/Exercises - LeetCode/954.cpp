class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> frequency;
        for (auto num : arr) frequency[num]++;
        
        sort(arr.begin(), arr.end());
        
        for (auto num : arr) {
            if (frequency[num] && frequency[num * 2]) {
                frequency[num]--;
                frequency[num * 2]--;
            }
        }
        
        for (auto [a, b] : frequency)
            if (b) return false;
        
        return true;
    }
};