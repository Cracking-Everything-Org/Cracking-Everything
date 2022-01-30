class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        // puedo usar vectores para noswap y swap o ahorrar espacio ya que necesito pocas variables
        int noSwapPrevious = 0;
        int swapPrevious = 1;

        for (int i = 1; i < A.size(); i++) {
            int noSwapCurrent = INT_MAX;
            int swapCurrent = INT_MAX;
            // comparo en sequencia
            if (A[i-1] < A[i] && B[i-1] < B[i]) {
                noSwapCurrent = min(noSwapCurrent, noSwapPrevious);
                swapCurrent = min(swapCurrent, swapPrevious + 1);
            }
            // compardo en diagonal y hago lower bound
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                noSwapCurrent = min(noSwapCurrent, swapPrevious);
                swapCurrent = min(swapCurrent, noSwapPrevious + 1);
            }
            noSwapPrevious = noSwapCurrent;
            swapPrevious = swapCurrent;
        }
        return min(noSwapPrevious, swapPrevious);
    }
};
