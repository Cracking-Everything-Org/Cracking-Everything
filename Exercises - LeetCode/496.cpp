class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            bool found = false;
            int j = 0;
            while (!found) {
                if (nums2[j] == nums1[i]) {
                    found = true;
                    break;
                }
                j++;
            }
            j++;
            while (j < nums2.size()) {
                if (nums2[j] > nums1[i]) {
                    ans.push_back(nums2[j]);
                    break;
                }
                j++;
            }
            if (j == nums2.size()) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
