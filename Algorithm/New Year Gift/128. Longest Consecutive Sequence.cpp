class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        int maximumSize = 0;
        int n = nums.size();
        
        for (int num : nums)
            seen.insert(num);
        
        for (int i = 0; i < n; i++) {
            int currentValue = nums[i];
            int currentSize = 0;
            
            // si existe el anterior, lo ignoro pq ya leí esa cadena
            if (seen.find(currentValue - 1) != seen.end())
                continue;
            
            // si es el primero de la cadena, trato de descubrir su tamaño
            while (seen.find(currentValue) != seen.end()) {
                currentSize++;
                currentValue++;
            }
            
            maximumSize = max(maximumSize, currentSize);
        }
        
        return maximumSize;
    }
};