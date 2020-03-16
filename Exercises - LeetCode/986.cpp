class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;

        int i = 0;
        int j = 0;
        while (i < A.size() && j < B.size()) {

            if (A[i][0] >= B[j][0] && A[i][0] <= B[j][1] ||
               B[j][0] >= A[i][0] && B[j][0] <= A[i][1] ) {
                vector<int> newInterval(2,0);
                newInterval[0] = max(A[i][0], B[j][0]);
                newInterval[1] = min(A[i][1], B[j][1]);
                ans.push_back(newInterval);
            }

            if (A[i][1] < B[j][1]) i++;
            else j++;
        }

        return ans;
    }
};
