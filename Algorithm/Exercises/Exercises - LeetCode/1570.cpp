class SparseVector {
public:
    unordered_map<int, int> hm;
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            hm[i] = nums[i];
        }    
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        
        for (auto entry : hm) {
            if (vec.hm.find(entry.first) != vec.hm.end()) {
                result += entry.second * vec.hm[entry.first];
            }
        }
        
        return result;
    }
};