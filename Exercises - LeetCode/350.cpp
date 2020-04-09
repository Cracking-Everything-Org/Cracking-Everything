class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        int n1Pointer = 0;
        int n2Pointer = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (n1Pointer < nums1.size() && n2Pointer < nums2.size()) {
            if (nums1[n1Pointer] == nums2[n2Pointer]) {
                intersection.push_back(nums1[n1Pointer]);
                n1Pointer++;
                n2Pointer++;
            } else {
                if (nums1[n1Pointer] < nums2[n2Pointer]) {
                    n1Pointer++;
                } else {
                    n2Pointer++;
                }
            }
        }
        return intersection;
    }
};
