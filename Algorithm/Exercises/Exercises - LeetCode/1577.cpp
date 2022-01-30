class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int triplets = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        unordered_map<long long, int> hm1;
        unordered_map<long long, int> hm2;

        for (int i = 0; i < nums1.size(); i++) {
            long long candidate = pow(nums1[i],2);
            if (hm1.find(candidate) == hm1.end()){
               hm1[candidate] = true;
            } else {
                hm1[candidate]++;
            }
        }

        for (int i = 0; i < nums2.size(); i++) {
            long long candidate = pow(nums2[i],2);
            if (hm2.find(candidate) == hm2.end()){
               hm2[candidate] = true;
            } else {
                hm2[candidate]++;
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                long long a = nums1[i];
                long long b = nums1[j];
                long long candidate = a * b;
                if (hm2.find(candidate) != hm2.end()) {
                    triplets += hm2[candidate];
                }
            }
        }

        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i + 1; j < nums2.size(); j++) {
                long long a = nums2[i];
                long long b = nums2[j];
                long long candidate = a * b;
                if (hm1.find(candidate) != hm1.end()) {
                    triplets += hm1[candidate];
                }
            }
        }

        return triplets;
    }
};
