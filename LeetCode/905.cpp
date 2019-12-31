class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int first = 0;
        int last = A.size()-1;
        while(first<A.size() && last>=0 && first<last){
            while(first<A.size() && A[first]%2 == 0) {
                first++;
                if(first == A.size() -1) return A;
            }
            while(last>=0 && A[last]%2 != 0){
                last--;
                if(last < 0) return A;
            }
            if(first<last){
                swap(A[first],A[last]);
                first++;
                last--;
            }
        }
        return A;
    }
};
