class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int j=0; j<A.size(); j++){
           reverse(A[j].begin(), A[j].end());
        }
        for(int k=0;k<A.size(); k++) {
            for(int i=0; i< A[k].size(); i++){
                if(A[k][i]==0) A[k][i]=1;
                else A[k][i]=0;
            }
        }
        return A;
    }
};
