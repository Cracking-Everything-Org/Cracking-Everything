class Solution {
public:
    vector<int> accumulativeWeights;
    
    Solution(vector<int>& w) {
        int accum = 0;
        for (int weight : w) {
            accum += weight;
            accumulativeWeights.push_back(accum);
        }
    }
    
    int pickIndex() {
        int random = rand() % accumulativeWeights.back() + 1;
        return binarySearch(random);
    }
    
    int binarySearch(int target) {
        int left = 0;
        int right = accumulativeWeights.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (accumulativeWeights[mid] < target) {
                left = mid + 1;
            } else right = mid;
        }
        
        return left;
    }
};