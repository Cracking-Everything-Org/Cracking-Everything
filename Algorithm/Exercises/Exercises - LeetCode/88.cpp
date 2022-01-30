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


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        
        for (int p = m + n - 1; p >= 0; p--) {
            if (p2 < 0) break;
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1--];
            } else {
                nums1[p] = nums2[p2--];
            }
        }
    }
};