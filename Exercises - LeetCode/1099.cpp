class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int left = 0;
        int right = A.size()-1;
        int numBefore = -1;
        if (A.size() == 1 || A[0] + A[1] > K) return numBefore;
        else if (A[right] + A[right-1] < K) return A[right] + A[right-1];
        while (left < right) {
            if (A[left] + A[right] < K){
                numBefore = max(numBefore, A[left] + A[right]);
                left++;
            } else if (A[left] + A[right] >= K){
                right--;
            }
        }
        return numBefore;
    }
};
