class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int longestLength = 0;
        int currentLength = 0;
        int startWindow = 0;
        int zerosFound = 0;
        for (int endWindow = 0; endWindow < A.size(); endWindow++) {
            currentLength++;
            if (A[endWindow] == 0) {
                zerosFound++;
                while (zerosFound > K) {
                    if (A[startWindow] == 0) {
                        zerosFound--;
                    }
                    startWindow++;
                    currentLength--;
                }
            }
            longestLength = max(longestLength, max(currentLength, endWindow - startWindow + 1));
        }
        return longestLength;
    }
};
