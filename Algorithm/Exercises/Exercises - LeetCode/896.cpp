class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() < 2) return true;

        bool mustBePositive = false;
        bool mustBeNegative = false;

        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1]) {
                if (mustBePositive || !mustBeNegative) {
                    mustBePositive = true;
                } else return false;
            } else if (A[i] < A[i-1]){
                if (!mustBePositive || mustBeNegative) {
                    mustBeNegative = true;
                } else return false;
            }
        }
        return true;
    }
};
