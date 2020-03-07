class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int current = 0;
        int last = A.size()-1;
        while(current < A.size()) {
            if(current %2 != 0){
                while(A[last] %2 == 0) last--;
                swap(A[current],A[last]);
            } else {
                while(A[last] %2 != 0) last--;
                swap(A[current],A[last]);
            }
            last = A.size()-1;
            current++;
        }
        return A;
    }
};
