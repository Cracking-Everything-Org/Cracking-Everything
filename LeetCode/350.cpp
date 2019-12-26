class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        unordered_map<int, int> hash;

        for (int i:nums1) {
            if(hash.find(i) != hash.end()){
                hash[i]++;
            }else{
                hash[i] = 1;
            }
        }
        for (int i:nums2) {
            if(hash.find(i) != hash.end()){
                hash[i]--;
                intersection.push_back(i);
            }
            if(hash[i]==0) hash.erase(i);
        }
        return intersection;
    }
};
