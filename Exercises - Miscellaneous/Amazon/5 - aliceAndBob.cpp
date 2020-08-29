// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, int K, int L) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() < K + L + 1) return -1;
    
    vector<int> prefixSum(A.size()+1, 0);
    int max = -1;
    
    for (int i = 1; i < prefixSum.size(); i++) {
            prefixSum[i] = prefixSum[i-1]+A[i-1];
        }
        
        for (int i = K; i < prefixSum.size(); i++) {
            int kSum = prefixSum[i]-prefixSum[i-K];
            
            for (int j = L; j < i-K; j++) {
                int lSum = prefixSum[j]-prefixSum[j-L];
                if (kSum + lSum > max) {
                    max = kSum + lSum;
                }
            }
            
            for (int j = i + L; j < prefixSum.size(); j++) {
                int lSum = prefixSum[j] - prefixSum[j-L];
                if (kSum + lSum > max) {
                    max = kSum + lSum;
                }
            }
        }
        return max;
}
