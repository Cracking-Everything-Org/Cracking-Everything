class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int finalIndex = m + n - 1;
        int firstIndex = m - 1;
        int secondIndex = n - 1;

        while (firstIndex >= 0 && secondIndex >= 0) {
            if (nums2[secondIndex] >= nums1[firstIndex]) {
                nums1[finalIndex] = nums2[secondIndex];
                secondIndex--;
            } else {
                nums1[finalIndex] = nums1[firstIndex];
                firstIndex--;
            }
            finalIndex--;
        }
        while (firstIndex >= 0) {
            nums1[finalIndex] = nums1[firstIndex];
            firstIndex--;
            finalIndex--;
        }
        while (secondIndex >= 0) {
            nums1[finalIndex] = nums2[secondIndex];
            finalIndex--;
            secondIndex--;
        }
    }
};
